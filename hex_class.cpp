#include "hex_class.h"

Hex::Hex() : size(0), hex_areas_number(0), red_pawns(0), blue_pawns(0), pawns_number(0) {};

void Hex::add_pawn(char pawn) {
	if (pawn == 'r') {
		red_pawns++;
		pawns_number++;
		hex_areas_number++;
	}
	else if (pawn == 'b') {
		blue_pawns++;
		pawns_number++;
		hex_areas_number++;
	}
	else if (pawn == '0') {
		hex_areas_number++;
	}
	pawns.push_back(pawn);
}

void Hex::count_size() {
	size = sqrt(hex_areas_number);
}

void Hex::resize_pawns_matrix() {
	pawns_matrix.resize(size, vector<char>(size, ' '));
}

void Hex::fill_pawns_matrix() {
	int index = 0;

	for (int k = 0; k < 2 * size - 1; k++) { 
		int row = (k < size) ? k : size - 1;
		int column = (k < size) ? 0 : k - size + 1;

		int i = row;
		int j = column;

		while (i >= 0 && j < size) {
			if (index < hex_areas_number) {
				pawns_matrix[i][j] = pawns[index++];
			}
			i--;
			j++;
		}
	}
}

void Hex::initialize_matrix() {
	count_size();
	resize_pawns_matrix();
	fill_pawns_matrix();
}

void Hex::reset_matrix() {
	hex_areas_number = 0;
	red_pawns = 0;
	blue_pawns = 0;
	pawns.clear();
	pawns_matrix.clear();
}
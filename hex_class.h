#pragma once
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Hex {
public:
	int size;
	int hex_areas_number; 
	int red_pawns;
	int blue_pawns; 
	int pawns_number; 

	vector<char> pawns; 
	vector<vector<char>> pawns_matrix;

	Hex();
	void add_pawn(char pawn);
	void count_size();
	void resize_pawns_matrix(); 
	void fill_pawns_matrix(); 

	void initialize_matrix();
	void reset_matrix();
};
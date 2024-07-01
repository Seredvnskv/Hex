#include <iostream>
#include <sstream>
#include <stack>
#include "hex_class.h";

#define RED_PAWN 'r'
#define BLUE_PAWN 'b'
#define EMPTY_AREA '0'

using namespace std;

struct Position {
    int x;
    int y;
};

vector<Position> neighbours = { {0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {1, 1} };

bool is_neighbour_valid(Position position, int row, int column) {
    return (position.x >= 0 && position.y >= 0 && position.x < row && position.y < column);
}

bool check_win(vector<vector<char>>& pawns_matrix, char pawn) {
    int row = pawns_matrix.size();
    int column = pawns_matrix[0].size();

    vector<vector<bool>> visited(row, vector<bool>(column, false)); // sledzenie odwiedzonych pozycji 
    
    stack<Position> stack; // przechowanie pozycji 

    if (pawn == RED_PAWN) {
        for (int i = 0; i < row; i++) {
            if (pawns_matrix[i][0] == RED_PAWN) {
                stack.push({ i, 0 }); // dodaj pozycje czerwonych w 1 kolumnie
            }
        }
    }
    else if (pawn == BLUE_PAWN) {
        for (int j = 0; j < column; j++) {
            if (pawns_matrix[0][j] == BLUE_PAWN) { // dodaj pozycje niebieskich w 1 rzedzie
                stack.push({ 0, j });
            }
        }
    }

    while (!stack.empty()) {
        Position position = stack.top();
        stack.pop();

        if (!visited[position.x][position.y]) {
            visited[position.x][position.y] = true;

            if ((pawn == RED_PAWN && position.y == column - 1) // Czerwony wygrywa przez polaczenie lewej i prawej strony
                || (pawn == BLUE_PAWN && position.x == row - 1)) { // Niebieski wygrywa przez polaczenie gory i dolu 
                return true;
            }

            for (Position nieghbour : neighbours) {
                Position new_position = { position.x + nieghbour.x, position.y + nieghbour.y };

                if (is_neighbour_valid(new_position, row, column) && pawns_matrix[new_position.x][new_position.y] == pawn) {
                    stack.push(new_position);
                }
            }
        }
    }

    return false;
}

bool is_correct(Hex& hex) {
    return ((hex.red_pawns == hex.blue_pawns) || (hex.red_pawns == hex.blue_pawns + 1));
}

bool is_possible(vector<vector<char>>& pawns_matrix, char pawn) {
    int row = pawns_matrix.size(); 
    int column = pawns_matrix[0].size();
    vector<vector<char>> temp_pawns_matrix;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (pawns_matrix[i][j] == pawn) {
                temp_pawns_matrix = pawns_matrix;
                temp_pawns_matrix[i][j] = EMPTY_AREA;

                if (!check_win(temp_pawns_matrix, pawn)) {
                    return true; // jesli po usunieciu pionka gracz nie wygrywa to plansza jest mozliwa
                }
            }
        }
    }
    return false;
}

int main() {
    string input;
    Hex hex;
    bool inside = false;
    int index_inside = 0;

    while (getline(cin, input)) {
        for (char c : input) {
            if (c == '<') {
                inside = true;
                index_inside = 0;
            }
            else if (inside) {
                if (c == '>') {
                    inside = false;
                }
                else if (c == RED_PAWN || c == BLUE_PAWN) {
                    hex.add_pawn(c);
                }
                else if (c == ' ' && index_inside == 1) {
                    hex.add_pawn(EMPTY_AREA);
                }
                index_inside++;
            }
        }
        if (input == "BOARD_SIZE") {
            hex.count_size();
            cout << hex.size << endl;
            hex.hex_areas_number = 0;
        }
        if (input == "PAWNS_NUMBER") {
            cout << hex.pawns_number << endl;
            hex.pawns_number = 0;
        }
        if (input == "IS_BOARD_CORRECT") {
            if (is_correct(hex)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }

            hex.red_pawns = 0;
            hex.blue_pawns = 0;
        }
        if (input == "IS_GAME_OVER") {
            hex.initialize_matrix();

            if (is_correct(hex)) {
                if (check_win(hex.pawns_matrix, RED_PAWN)) {
                    cout << "YES RED" << endl;
                }
                else if (check_win(hex.pawns_matrix, BLUE_PAWN)) {
                    cout << "YES BLUE" << endl;
                }
                else {
                    cout << "NO" << endl;
                }
            }
            else {
                cout << "NO" << endl;
            }

            hex.reset_matrix();
        }
        if (input == "IS_BOARD_POSSIBLE") {
            hex.initialize_matrix();

            if (is_correct(hex)) {
                if (check_win(hex.pawns_matrix, RED_PAWN)) {
                    if (is_possible(hex.pawns_matrix, RED_PAWN) && (hex.red_pawns == hex.blue_pawns + 1)) {
                        cout << "YES" << endl;
                    }
                    else {
                        cout << "NO" << endl;
                    }
                }
                else if (check_win(hex.pawns_matrix, BLUE_PAWN)) {
                    if (is_possible(hex.pawns_matrix, BLUE_PAWN) && (hex.red_pawns == hex.blue_pawns)) {
                        cout << "YES" << endl;
                    }
                    else {
                        cout << "NO" << endl;
                    }
                }
                else {
                    cout << "YES" << endl;
                }
            }
            else {
                cout << "NO" << endl;
            }

            hex.reset_matrix();
        }
    }

    return 0;
}
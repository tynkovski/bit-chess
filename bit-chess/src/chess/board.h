#pragma once

#include <functional>
#include "utils.h"
#include "consts.h"
#include "defs.h"

color get_opposite_color(color color);

board create_board();
board fill_board();
board make_move(board board, position from, position to);

position_list get_possible_moves(board board, position position);
position_list get_pieces_positions(board board);

piece_list get_friends_positions(board board, position position);

position string_to_position(string input);

string position_to_string(position position);
string board_to_string(board board);

char piece_to_char(piece piece);
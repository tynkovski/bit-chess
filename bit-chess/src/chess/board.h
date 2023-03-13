#pragma once

#include <functional>
#include "utils.h"
#include "consts.h"
#include "defs.h"

board create_board();
board fill_board();
board make_move(board board, position from, position to);

position_list get_possible_moves(board board, position position);

position_list get_pieces_positions(board board);
position_list get_enemies_positions(board board, position position);
position_list get_friends_positions(board board, position position);

position string_to_position(string input);
string position_to_string(position position);

char piece_to_char(piece piece);
piece char_to_piece(char character);
string board_to_string(board board);
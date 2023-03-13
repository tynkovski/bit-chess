#pragma once

#include "consts.h"
#include "defs.h"

bool in_range(u8 x, u8 low, u8 high);
u8 apply_mask(u8 value, u8 mask);
bool check_bit(u8 value, u8 mask);
color get_color(piece piece);
color get_opposite_color(color color);
move get_move_strategy(piece piece);
piece get_piece_type(piece piece);
bool is_black_piece(piece piece);
bool is_white_piece(piece piece);
bool is_ghost_piece(piece piece);
bool is_piece(piece piece);
bool not_piece(piece piece);
bool is_out_of_board(position position);
bool is_invalid_input(string input);
bool is_long_moving(piece piece);
bool is_cross_moving(piece piece);
bool is_diagonal_moving(piece piece);
bool is_jump_moving(piece piece);
vector<string> split(const string& s, const regex& sep_regex = regex{ "\\s+" });
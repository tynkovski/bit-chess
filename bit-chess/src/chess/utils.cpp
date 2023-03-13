#include "utils.h"

bool in_range(u8 x, u8 low, u8 high) {
  return (x - low) <= (high - low);
}

u8 apply_mask(u8 value, u8 mask) {
  return value & mask;
}

bool check_bit(u8 value, u8 mask) {
  return apply_mask(value, mask) == mask;
}

color get_color(piece piece) {
  return apply_mask(piece, COLOR_MASK);
}

color get_opposite_color(color color) {
  return color == BLACK ? WHITE : BLACK;
}

move get_move_strategy(piece piece) {
  return apply_mask(piece, MOVE_MASK);
}

piece get_piece_type(piece piece) {
  return apply_mask(piece, PIECE_MASK);
}

bool is_black_piece(piece piece) {
  return get_color(piece) == BLACK;
}

bool is_white_piece(piece piece) {
  return get_color(piece) == WHITE;
}

bool is_ghost_piece(piece piece) {
  return check_bit(piece, OUT_OF_BOARD);
}

bool is_piece(piece piece) {
  return !is_ghost_piece(piece) && piece != NO_PIECE;
}

bool not_piece(piece piece) {
  return is_ghost_piece(piece) || piece == NO_PIECE;
}

bool is_out_of_board(position position) {
  return !in_range(position, BOARD_A1, BOARD_H8)
    || position % 10 == 0
    || position % 10 == 9;
}

bool is_invalid_input(string input) {
  return input.size() != 2
    || !in_range(input[0], 'a', 'h')
    || !in_range(input[1], '1', '8');
}

bool is_long_moving(piece piece) {
  return check_bit(get_move_strategy(piece), LONG_MOVE);
}

bool is_cross_moving(piece piece) {
  return check_bit(get_move_strategy(piece), CROSS_MOVE);
}

bool is_diagonal_moving(piece piece) {
  return check_bit(get_move_strategy(piece), DIAGONAL_MOVE);
}

bool is_jump_moving(piece piece) {
  return check_bit(get_move_strategy(piece), JUMP_MOVE);
}

vector<string> split(
  const string& input, 
  const regex& sep_regex
) {
  std::sregex_token_iterator iter(input.begin(), input.end(), sep_regex, -1), end;
  return { iter, end };
}
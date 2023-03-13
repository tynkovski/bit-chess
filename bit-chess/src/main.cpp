#include <iostream>
#include "chess/board.h";

void print_board(piece_list board) {
  std::cout << board_to_string(board);
}

string read() {
  string input = "";
  std::cin >> input;
  return input;
}

position input_move() {
  return string_to_position(read());
}

board parse_fen(string fen) {
  board new_board = create_board();

  vector<string> fen_elements = split(fen);

  string pieces       = fen_elements[0];
  string side         = fen_elements[1];
  string castling     = fen_elements[2];
  string enpassant    = fen_elements[3];
  string half_move    = fen_elements[4];
  string full_move    = fen_elements[5];

  u8 rank = 0;
  for (string row : split(pieces, regex{ "/" })) {
    u8 file = 0;

    for (char c : row) {
      u8 current_pos = rank * RANK_STEP + file + BOARD_A1;

      if (isdigit(c)) {
        file += c - '0';
      } else {
        new_board[current_pos] = char_to_piece(c);
        file++;
      }
    }
    rank++;
  }

  return new_board;
}

int main() {
  board board = fill_board();

  bool has_error = false;
  try {
    while (!has_error) {
      print_board(board);
      position pos = input_move();
    }
  } catch (const std::exception& e) {
    has_error = true;
    std::cout << e.what() << '\n';
  }
  
  return 0;
}
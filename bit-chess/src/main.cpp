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

int main() {
  piece_list board = fill_board();
  color color = WHITE;

  position_list pieces = get_pieces_positions(board);
  for (position f : pieces) {
    std::cout << "board[" << (int)f << "] = " << position_to_string(f) << '\n';
  }

  bool has_error = false;
  try {
    while (!has_error) {
      print_board(board);
      position pos = input_move();
      position_list friends = get_friends_positions(board, pos);
      for (position f : friends) {
        std::cout << "board[" << (int)f << "] = " << position_to_string(f) << '\n';
      }
    }
  } catch (const std::exception& e) {
    has_error = true;
    std::cout << e.what() << '\n';
  }
  
  return 0;
}
#include "board.h"

board create_board() {
  board board(BOARD_SIZE);

  for (position i = 0; i < BOARD_SIZE; ++i) {
    board[i] = is_out_of_board(i) ? OUT_OF_BOARD : NO_PIECE;
  }

  return board;
}

board fill_board() {
  board board = create_board();

  piece_list pieces = {
    ROOK, KNIGNT, BISHOP, QUEEN, KING, BISHOP, KNIGNT, ROOK,
  };

  for (position i = BOARD_A1, j = 0; i <= BOARD_H1; ++i, ++j) {
    board[i] = WHITE + pieces[j];
    board[i + (BOARD_A8 - BOARD_A1)] = BLACK + pieces[j];
  }

  for (position i = BOARD_A2; i <= BOARD_H2; ++i) {
    board[i] = WHITE + PAWN;
    board[i + (BOARD_A7 - BOARD_A2)] = BLACK + PAWN;
  }

  return board;
}

position_list filter_positions(piece_list board, std::function<bool(position)> fun) {
  position_list out_list;

  for (position i = 0; i < board.size(); i++) {
    if (fun(i)) out_list.push_back(i);
  }

  return out_list;
}

position_list get_pieces_positions(board board) {
  return filter_positions(
    board, [board](const position p) {
      return !is_out_of_board(p) && is_piece(board[p]);
    }
  );
}

position_list get_enemies_positions(board board, position pos) {
  return filter_positions(
    board, [board, pos](const position p) {
      return !is_out_of_board(p)
        && is_piece(board[p])
        && get_color(board[p]) != get_color(board[pos]);
    }
  );
}

position_list get_friends_positions(board board, position pos) {
  return filter_positions(
    board, [board, pos](const position p) {
      return !is_out_of_board(p)
        && is_piece(board[p])
        && get_color(board[p]) == get_color(board[pos])
        && p != pos;
    }
  );
}

position_list get_possible_moves(
  board board,
  position position
) {
  position_list moves;
  //position_list friends = get_friends_positions(board, position);

  return moves;
}

board make_move(
  board old_board,
  position from, 
  position to
) {
  board new_board = old_board;

  new_board[from] = NO_PIECE;
  new_board[to] = old_board[from];

  return new_board;
}

char piece_to_char(piece piece) {
  return not_piece(piece) ? '.'
    : to_char_dictionary {
      { PAWN + WHITE, 'P'},
      { KNIGNT + WHITE, 'N'},
      { BISHOP + WHITE, 'B'},
      { ROOK + WHITE, 'R'},
      { QUEEN + WHITE, 'Q'},
      { KING + WHITE, 'K'},
      { PAWN + BLACK, 'p'},
      { KNIGNT + BLACK, 'n'},
      { BISHOP + BLACK, 'b'},
      { ROOK + BLACK, 'r'},
      { QUEEN + BLACK, 'q'},
      { KING + BLACK, 'k'},
  } [piece] ;
}

piece char_to_piece(char character) {
  return to_piece_dictionary {
    {'P', PAWN + WHITE},
    {'N', KNIGNT + WHITE},
    {'B', BISHOP + WHITE},
    {'R', ROOK + WHITE},
    {'Q', QUEEN + WHITE},
    {'K', KING + WHITE},
    {'p', PAWN + BLACK},
    {'n', KNIGNT + BLACK},
    {'b', BISHOP + BLACK},
    {'r', ROOK + BLACK},
    {'q', QUEEN + BLACK},
    {'k', KING + BLACK},
  } [character] ;
}

string board_to_string(board board) {
  string stream = "";

  for (uint8_t rank = BOARD_A8; rank >= BOARD_A1; rank -= RANK_STEP) {
    for (uint8_t i = rank; i <= rank + BOARD_WIDTH; ++i) {
      stream += piece_to_char(board[i]);
    }
    stream += '\n';
  }

  return stream;
}

position string_to_position(string input) {
  if (is_invalid_input(input)) {
    throw std::exception("invalid input");
  }

  uint8_t file = std::tolower(input[0]) - 'a';
  uint8_t rank = input[1] - '1';

  return rank * 10 + BOARD_A1 + file;
}

string position_to_string(position pos) {
  if (!in_range(pos, BOARD_A1, BOARD_H8)) {
    throw std::exception("invalid position");
  }

  position new_pos = pos - BOARD_A1;
  char rank = new_pos / 10 % 10 + '1';
  char file = new_pos % 10 + 'a';

  return string(1, file) + string(1, rank);
}

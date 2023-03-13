#include "board.h"

board create_board() {
  board board{};

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

position_list filter_board(board board, std::function<bool(position)> fun) {
  position_list out_list;

  for (position i = 0; i < BOARD_SIZE; i++) {
    if (fun(i)) out_list.push_back(i);
  }

  return out_list;
}

template <typename U, typename V>
unordered_map<U, V> zip(vector<U> keys, vector<V> values) {
  unordered_map<U, V> o;

  for (size_t i = 0; i < std::min(keys.size(), values.size()); ++i) {
    o[keys[i]] = values[i];
  }

  return o;
}

position_list get_pieces_positions(board board) {
  return filter_board(
    board, [board](const position p) {
      return !is_out_of_board(p) && is_piece(board[p]);
    }
  );
}

position_list get_enemies_positions(board board, position pos) {
  return filter_board(
    board, [board, pos](const position p) {
      return !is_out_of_board(p)
        && is_piece(board[p])
        && get_color(board[p]) != get_color(board[pos]);
    }
  );
}

position_list get_friends_positions(board board, position pos) {
  return filter_board(
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
  position piece_position
) {
  position_list moves;

  position_list friends = get_friends_positions(board, piece_position);
  position_list enemies = get_enemies_positions(board, piece_position);



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

char_list get_pieces_characters() {
  return { 
    'P', 'N', 'B', 'R', 'Q', 'K',
    'p', 'n', 'b', 'r', 'q', 'k' 
  };
}

piece_list get_pieces_list() {
  return {
    PAWN + WHITE,
    KNIGNT + WHITE,
    BISHOP + WHITE,
    ROOK + WHITE,
    QUEEN + WHITE,
    KING + WHITE,
    PAWN + BLACK,
    KNIGNT + BLACK,
    BISHOP + BLACK,
    ROOK + BLACK,
    QUEEN + BLACK,
    KING + BLACK,
  };
}

char piece_to_char(piece piece) {
  to_char_dictionary dictionary = zip(get_pieces_list(), get_pieces_characters());
  if (!dictionary.contains(piece)) {
    return '.';
  }
  return dictionary[piece];
}

piece char_to_piece(char character) {
  to_piece_dictionary dictionary = zip(get_pieces_characters(), get_pieces_list());
  if (!dictionary.contains(character)) {
    return '?';
  }
  return dictionary[character];
}

string board_to_string(board board) {
  string stream = "";

  for (u8 rank = BOARD_A8; rank >= BOARD_A1; rank -= RANK_STEP) {
    for (u8 i = rank; i < rank + BOARD_WIDTH; ++i) {
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

  u8 file = std::tolower(input[0]) - 'a';
  u8 rank = input[1] - '1';

  return rank * RANK_STEP + BOARD_A1 + file;
}

string position_to_string(position pos) {
  if (!in_range(pos, BOARD_A1, BOARD_H8)) {
    throw std::exception("invalid position");
  }

  position new_pos = pos - BOARD_A1;
  char rank = new_pos / RANK_STEP % RANK_STEP + '1';
  char file = new_pos % RANK_STEP + 'a';

  return string(1, file) + string(1, rank);
}

#pragma once

#include "defs.h"

const string START_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

const piece NO_PIECE      = 0b00000000;
const piece OUT_OF_BOARD  = 0b10000000;
const piece MOVED         = 0b01000000;

const piece WHITE         = 0b00000000;
const piece BLACK         = 0b00100000;
const piece COLOR_MASK    = 0b00100000;

const piece PAWN          = 0b00000001;
const piece KNIGNT        = 0b00010000;
const piece BISHOP        = 0b00001010;
const piece ROOK          = 0b00001100;
const piece QUEEN         = 0b00001110;
const piece KING          = 0b00000110;
const piece PIECE_MASK    = 0b00011111;

const piece JUMP_MOVE     = 0b00010000;
const piece LONG_MOVE     = 0b00001000;
const piece CROSS_MOVE    = 0b00000100;
const piece DIAGONAL_MOVE = 0b00000010;
const piece FORWARD_MOVE  = 0b00000001;
const piece MOVE_MASK     = 0b00011111;

const position BOARD_SIZE  = 120;
const position BOARD_WIDTH = 8;
const position RANK_STEP   = 10;
const position FILE_STEP   = 1;

const position BOARD_A1   = 21;
const position BOARD_A2   = 31;
const position BOARD_A7   = 81;
const position BOARD_A8   = 91;

const position BOARD_H1   = 28;
const position BOARD_H2   = 38;
const position BOARD_H7   = 91;
const position BOARD_H8   = 98;

const direction DIRECTION_UP    = RANK_STEP;
const direction DIRECTION_RIGHT = FILE_STEP;
const direction DIRECTION_DOWN  = -DIRECTION_UP;
const direction DIRECTION_LEFT  = -DIRECTION_RIGHT;

const direction JUMP_UP_RIGHT   = 2 * DIRECTION_UP + DIRECTION_RIGHT;
const direction JUMP_UP_LEFT    = 2 * DIRECTION_UP + DIRECTION_LEFT;
const direction JUMP_RIGHT_UP   = DIRECTION_UP + 2 * DIRECTION_RIGHT;
const direction JUMP_LEFT_UP    = DIRECTION_UP + 2 * DIRECTION_LEFT;
const direction JUMP_DOWN_RIGHT = -JUMP_UP_LEFT;
const direction JUMP_DOWN_LEFT  = -JUMP_UP_RIGHT;
const direction JUMP_RIGHT_DOWN = -JUMP_LEFT_UP;
const direction JUMP_LEFT_DOWN  = -JUMP_RIGHT_UP;

const direction WHITE_PAWN_MOVE      = DIRECTION_UP;
const direction WHITE_PAWN_LONG_MOVE = 2 * DIRECTION_UP;
const direction BLACK_PAWN_MOVE      = -WHITE_PAWN_MOVE;
const direction BLACK_PAWN_LONG_MOVE = -WHITE_PAWN_LONG_MOVE;
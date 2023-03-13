#pragma once

#include "defs.h"

const piece NO_PIECE      = 0b00000000;
const piece OUT_OF_BOARD  = 0b11111111;

const piece SHORT_MOVE    = 0b00000000;
const piece LONG_MOVE     = 0b01000000;
const piece CROSS_MOVE    = 0b00010000;
const piece DIAGONAL_MOVE = 0b00100000;
const piece KNIGHT_MOVE   = 0b00000000;
const piece MOVE_MASK     = 0b01110000;

const piece WHITE         = 0b00000000;
const piece BLACK         = 0b00001000;
const piece COLOR_MASK    = 0b00001000;

const piece PAWN          = 0b00000001;
const piece KNIGNT        = 0b00000010;
const piece BISHOP        = 0b00000011;
const piece ROOK          = 0b00000100;
const piece QUEEN         = 0b00000101;
const piece KING          = 0b00000110;
const piece PIECE_MASK    = 0b00000111;

const position BOARD_SIZE  = 120;
const position BOARD_WIDTH = 8;
const position RANK_STEP   = 10;

const position BOARD_A1   = 21;
const position BOARD_A2   = 31;
const position BOARD_A7   = 81;
const position BOARD_A8   = 91;

const position BOARD_H1   = 28;
const position BOARD_H2   = 38;
const position BOARD_H7   = 91;
const position BOARD_H8   = 98;

const direction DIRECTION_UP    = 10;
const direction DIRECTION_RIGHT = 1;
const direction DIRECTION_DOWN  = -DIRECTION_UP;
const direction DIRECTION_LEFT  = -DIRECTION_RIGHT;

const direction JUMP_UP_RIGHT   = 21;
const direction JUMP_UP_LEFT    = 19;
const direction JUMP_RIGHT_UP   = 12;
const direction JUMP_LEFT_UP    = 8;
const direction JUMP_DOWN_RIGHT = -JUMP_UP_LEFT;
const direction JUMP_DOWN_LEFT  = -JUMP_UP_RIGHT;
const direction JUMP_RIGHT_DOWN = -JUMP_LEFT_UP;
const direction JUMP_LEFT_DOWN  = -JUMP_RIGHT_UP;
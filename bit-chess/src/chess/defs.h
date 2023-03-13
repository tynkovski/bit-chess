#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <regex>

using std::string;
using std::regex;
using std::vector;
using std::unordered_map;

typedef signed char        i8;  // -128 - 127
typedef unsigned char      u8;  // 0 - 255
typedef unsigned int       u32; // 0 - 4294967295 
typedef unsigned long long u64; // 0 - 18446744073709551615

typedef u8 piece;     // 0 - 15
typedef u8 position;  // 0 - 120
typedef u8 color;     // white / black
typedef u8 move;      // long or short cross and/or diagonal or short jump.
typedef i8 direction; // -21 - 21

typedef vector<piece> piece_list; // Contain just pieces.
typedef vector<piece> board;      // Contains all squares. Can contain NO_PIECE.
typedef vector<position> position_list;

typedef unordered_map<piece, char> to_char_dictionary;
typedef unordered_map<char, piece> to_piece_dictionary;
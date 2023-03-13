#pragma once

#include <string>
#include <regex>
#include <array>
#include <vector>
#include <unordered_map>

using std::string;
using std::regex;

typedef signed char        i8;  // -128 - 127
typedef unsigned char      u8;  // 0 - 255
typedef unsigned int       u32; // 0 - 4294967295 
typedef unsigned long long u64; // 0 - 18446744073709551615

typedef u8 piece;     // 0 - 15
typedef u8 position;  // 0 - 120
typedef u8 color;     // white / black
typedef u8 move;      // long or short cross and/or diagonal or short jump.
typedef i8 direction; // -21 - 21

using std::array;
using std::vector;
using std::unordered_map;

typedef vector<piece> piece_list;
typedef vector<char> char_list;
typedef array<piece, 120> board;
typedef vector<position> position_list;

typedef unordered_map<piece, char> to_char_dictionary;
typedef unordered_map<char, piece> to_piece_dictionary;
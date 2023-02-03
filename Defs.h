#ifndef DEFS_H
#define DEFS_H

#define WHITE 0
#define BLACK 1
#define NO_COLOR 2
#define PAWN 0
#define KNIGHT 1
#define BISHOP 2
#define ROOK 3
#define QUEEN 4
#define KING 5

const unsigned int a1 = 0;
const unsigned int b1 = 1;
const unsigned int c1 = 2;
const unsigned int d1 = 3;
const unsigned int e1 = 4;
const unsigned int f1 = 5;
const unsigned int g1 = 6;
const unsigned int h1 = 7;

const unsigned int a2 = 16;
const unsigned int b2 = 17;
const unsigned int c2 = 18;
const unsigned int d2 = 19;
const unsigned int e2 = 20;
const unsigned int f2 = 21;
const unsigned int g2 = 22;
const unsigned int h2 = 23;

const unsigned int a3 = 32;
const unsigned int b3 = 33;
const unsigned int c3 = 34;
const unsigned int d3 = 35;
const unsigned int e3 = 36;
const unsigned int f3 = 37;
const unsigned int g3 = 38;
const unsigned int h3 = 39;

const unsigned int a4 = 48;
const unsigned int b4 = 49;
const unsigned int c4 = 50;
const unsigned int d4 = 51;
const unsigned int e4 = 52;
const unsigned int f4 = 53;
const unsigned int g4 = 54;
const unsigned int h4 = 55;

const unsigned int a5 = 64;
const unsigned int b5 = 65;
const unsigned int c5 = 66;
const unsigned int d5 = 67;
const unsigned int e5 = 68;
const unsigned int f5 = 69;
const unsigned int g5 = 70;
const unsigned int h5 = 71;

const unsigned int a6 = 80;
const unsigned int b6 = 81;
const unsigned int c6 = 82;
const unsigned int d6 = 83;
const unsigned int e6 = 84;
const unsigned int f6 = 85;
const unsigned int g6 = 86;
const unsigned int h6 = 87;

const unsigned int a7 = 96;
const unsigned int b7 = 97;
const unsigned int c7 = 98;
const unsigned int d7 = 99;
const unsigned int e7 = 100;
const unsigned int f7 = 101;
const unsigned int g7 = 102;
const unsigned int h7 = 103;

const unsigned int a8 = 112;
const unsigned int b8 = 113;
const unsigned int c8 = 114;
const unsigned int d8 = 115;
const unsigned int e8 = 116;
const unsigned int f8 = 117;
const unsigned int g8 = 118;
const unsigned int h8 = 119;

#define OFF_THE_BOARD 127

#define QUIET_MOVE 0
#define CAPTURE_MOVE 1
#define DOUBLE_PAWN_MOVE 2
#define EN_PASSANT_CAPTURE 3
#define CASTLE_MOVE 4
#define QUIET_KNIGHT_PROMOTION 5
#define QUIET_BISHOP_PROMOTION 6
#define QUIET_ROOK_PROMOTION 7
#define QUIET_QUEEN_PROMOTION 8
#define CAPTURE_KNIGHT_PROMOTION 9
#define CAPTURE_BISHOP_PROMOTION 10
#define CAPTURE_ROOK_PROMOTION 11
#define CAPTURE_QUEEN_PROMOTION 12


#endif // DEFS_H

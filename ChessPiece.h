#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include "Defs.h"

class ChessPiece
{
    protected:
        ChessPiece(const int &pColor, const int &pType, const unsigned int &pLocation = OFF_THE_BOARD):
            color(pColor), type(pType), location(pLocation) {}
        int color;
        int type;
        unsigned int location;

    public:
        virtual ~ChessPiece() {}
        int getColor() const { return color; }
        int getType() const { return type; }
        virtual char getShortName() const = 0;
        unsigned int getFile() const { return location & 0x88; }
        unsigned int getRank() const { return (location >> 4) + 1; }
        void setType(const int &pType) { type = pType; }
        void setLocation(const int &pLocation) { location = pLocation; }
};

class WhitePawn : public ChessPiece
{
    public:
        WhitePawn(const unsigned int &pLocation):
            ChessPiece(WHITE, PAWN, pLocation) {}
        virtual char getShortName() const { return 'P'; }
};

class WhiteRook : public ChessPiece
{
    public:
        WhiteRook(const unsigned int &pLocation):
            ChessPiece(WHITE, ROOK, pLocation) {}
        virtual char getShortName() const { return 'R'; }
};

class WhiteKnight : public ChessPiece
{
    public:
        WhiteKnight(const unsigned int &pLocation):
            ChessPiece(WHITE, KNIGHT, pLocation) {}
        virtual char getShortName() const { return 'N'; }
};

class WhiteBishop : public ChessPiece
{
    public:
        WhiteBishop(const unsigned int &pLocation):
            ChessPiece(WHITE, BISHOP, pLocation) {}
        virtual char getShortName() const { return 'B'; }
};

class WhiteQueen : public ChessPiece
{
    public:
        WhiteQueen(const unsigned int &pLocation):
            ChessPiece(WHITE, QUEEN, pLocation) {}
        virtual char getShortName() const { return 'Q'; }
};

class WhiteKing : public ChessPiece
{
    public:
        WhiteKing(const unsigned int &pLocation):
            ChessPiece(WHITE, KING, pLocation) {}
        virtual char getShortName() const { return 'K'; }
};

class BlackPawn : public ChessPiece
{
    public:
        BlackPawn(const unsigned int &pLocation):
            ChessPiece(BLACK, PAWN, pLocation) {}
        virtual char getShortName() const { return 'p'; }
};

class BlackRook : public ChessPiece
{
    public:
        BlackRook(const unsigned int &pLocation):
            ChessPiece(BLACK, ROOK, pLocation) {}
        virtual char getShortName() const { return 'r'; }
};

class BlackKnight : public ChessPiece
{
    public:
        BlackKnight(const unsigned int &pLocation):
            ChessPiece(BLACK, KNIGHT, pLocation) {}
        virtual char getShortName() const { return 'n'; }
};

class BlackBishop : public ChessPiece
{
    public:
        BlackBishop(const unsigned int &pLocation):
            ChessPiece(BLACK, BISHOP, pLocation) {}
        virtual char getShortName() const { return 'b'; }
};

class BlackQueen : public ChessPiece
{
    public:
        BlackQueen(const unsigned int &pLocation):
            ChessPiece(BLACK, QUEEN, pLocation) {}
        virtual char getShortName() const { return 'q'; }
};

class BlackKing : public ChessPiece
{
    public:
        BlackKing(const unsigned int &pLocation):
            ChessPiece(BLACK, KING, pLocation) {}
        virtual char getShortName() const { return 'k'; }
};


#endif // CHESSPIECE_H

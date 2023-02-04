#ifndef CHESSPOSITION_H
#define CHESSPOSITION_H

#include <iostream>
#include "ChessPiece.h"
#include "ChessMove.h"

class MoveGenerator;
class ChessPosition
{
    public:
        ChessPosition();
        explicit ChessPosition(const std::string &fenString);
        ChessPosition(const ChessPosition &chessPosition);
        ~ChessPosition();
        ChessPosition operator=(const ChessPosition &chessPosition);
        bool static isOffTheBoard(const unsigned int &squareIndex) { return squareIndex & 0x88; }
        static std::string getSquareName(const unsigned int &squareIndex);
        static unsigned int getSquareNumber(const std::string &squareName);
        static unsigned int getRank(const unsigned int &squareIndex);

        ChessPiece* &operator[](const unsigned int &squareIndex) const { return squares[squareIndex]; }
        void makeMove(const ChessMove &chessMove);
        int getSideToMove() const { return sideToMove; }
        int getEnPassantValue() const { return enPassantValue; }
        void setEnPassantValue(const unsigned int &pEnPassantValue) { enPassantValue = pEnPassantValue; }
        MoveGenerator* getMoveGenerator() { return moveGenerator; }
        unsigned int getColor(const unsigned &index) const;

    private:
        ChessPiece** squares;
        int sideToMove;
        int enPassantValue;
        MoveGenerator *moveGenerator;
};

std::ostream &operator<<(std::ostream& os, const ChessPosition &chessPosition);

#endif // CHESSPOSITION_H

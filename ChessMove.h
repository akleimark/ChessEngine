#ifndef CHESSMOVE_H
#define CHESSMOVE_H

#include "Defs.h"
#include <iostream>

/**
 * @author Anders Kleimark
 * @brief Klassen 'ChessMove' skapar drag.
 */
class ChessMove
{
    public:
        ChessMove(const unsigned int &fSquare, const unsigned int &tSquare, const unsigned int &pFlag = QUIET_MOVE):
            fromSquare(fSquare), toSquare(tSquare), flag(pFlag), score(0) {}

        /**
         * @brief getFromSquare ger startrutan enligt 0x88-systemet.
         * @return
         */
        unsigned int getFromSquare() const { return fromSquare; }
        unsigned int getToSquare() const { return toSquare; }
        unsigned int getFlag() const { return flag; }
        unsigned int getScore() const { return score; }
        bool operator<(const ChessMove &chessMove) const { return chessMove.getScore() < score; }
        bool operator==(const ChessMove &chessMove);

    private:
        unsigned int fromSquare;
        unsigned int toSquare;
        unsigned int flag;
        unsigned int score;

};

std::ostream& operator<<(std::ostream &os, const ChessMove &chessMove);

#endif // CHESSMOVE_H

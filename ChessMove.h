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


        unsigned int getFromSquare() const { return fromSquare; }
        unsigned int getToSquare() const { return toSquare; }
        unsigned int getFlag() const { return flag; }
        unsigned int getScore() const { return score; }
        bool operator<(const ChessMove &chessMove) const { return chessMove.getScore() < score; }
        bool operator==(const ChessMove &chessMove);

    private:
        /// Den här datamedlemmen anger från vilken ruta, som draget utgår från. Rutan anges enligt 0x88-systemet.
        unsigned int fromSquare;
        /// Den här datamedlemmen anger destinationsrutan. Rutan anges enligt 0x88-systemet.
        unsigned int toSquare;
        /// Den här datamedlemmen anger vilken typ av drag, som det rör sig om. Exempel på typer av drag är QUIET_MOVE, CASTLE_MOVE med flera.
        unsigned int flag;
        /// Den här datamedlemmen anger vilken poäng som draget har. Ett drag med en högre poäng rankas högre och prövas tidigare, än ett drag med en lägre poäng.
        /// Drag som involverar ett slag ger exempelvis generellt en högre poäng, än "vanliga och lugna drag".
        unsigned int score;

};

std::ostream& operator<<(std::ostream &os, const ChessMove &chessMove);

#endif // CHESSMOVE_H

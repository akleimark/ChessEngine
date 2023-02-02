#ifndef MOVEGENERATOR_H
#define MOVEGENERATOR_H

#include "ChessPosition.h"
#include <vector>

class MoveGenerator
{
    public:
        MoveGenerator(const ChessPosition &pChessPosition);
        void generate(const int &side);
        const ChessMove& operator[](const unsigned int &index) const { return list[index]; }
        ChessMove get(const unsigned int &index) const { return list.at(index); }
        std::vector<ChessMove>::const_iterator cbegin() const { return list.cbegin(); }
        std::vector<ChessMove>::const_iterator cend() const { return list.cend(); }
        unsigned int size() const { return list.size(); }

    private:
        const ChessPosition &chessPosition;
        std::vector<ChessMove> list;

};

std::ostream& operator<<(std::ostream &os, const MoveGenerator &generator);

#endif // MOVEGENERATOR_H

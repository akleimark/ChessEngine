#include "ChessMove.h"
#include "ChessPosition.h"

bool ChessMove:: operator==(const ChessMove &chessMove)
{
    if(fromSquare == chessMove.getFromSquare() && toSquare == chessMove.getToSquare())
    {
        return true;
    }

    return false;
}

std::ostream& operator<<(std::ostream &os, const ChessMove &chessMove)
{
    os << ChessPosition::getSquareName(chessMove.getFromSquare()) << "-" << ChessPosition::getSquareName(chessMove.getToSquare());

    return os;
}






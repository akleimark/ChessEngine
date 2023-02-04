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
    if((chessMove.getFromSquare() == e1 && chessMove.getToSquare() == g1 && chessMove.getFlag() == CASTLE_MOVE)
            || (chessMove.getFromSquare() == e8 && chessMove.getToSquare() == g8 && chessMove.getFlag() == CASTLE_MOVE))
    {
        os << "O-O";
        return os;
    }
    if((chessMove.getFromSquare() == e1 && chessMove.getToSquare() == c1 && chessMove.getFlag() == CASTLE_MOVE)
            || (chessMove.getFromSquare() == e8 && chessMove.getToSquare() == c8 && chessMove.getFlag() == CASTLE_MOVE))
    {
        os << "O-O-O";
        return os;
    }
    os << ChessPosition::getSquareName(chessMove.getFromSquare());
    if(chessMove.getFlag() == QUIET_MOVE || (QUIET_KNIGHT_PROMOTION <= chessMove.getFlag() && chessMove.getFlag() <= QUIET_QUEEN_PROMOTION) ||
            chessMove.getFlag() == DOUBLE_PAWN_MOVE)
    {
        os << "-";
    }
    else if(chessMove.getFlag() == CAPTURE_MOVE || chessMove.getFlag() == EN_PASSANT_CAPTURE || (CAPTURE_KNIGHT_PROMOTION <= chessMove.getFlag() && chessMove.getFlag() <= CAPTURE_QUEEN_PROMOTION))
    {
        os << "x";
    }
    os << ChessPosition::getSquareName(chessMove.getToSquare());

    if (chessMove.getFlag() == EN_PASSANT_CAPTURE)
    {
        os << " e.p";
    }
    else if(chessMove.getFlag() == QUIET_KNIGHT_PROMOTION || chessMove.getFlag() == CAPTURE_KNIGHT_PROMOTION)
    {
        os << "N";
    }
    else if(chessMove.getFlag() == QUIET_BISHOP_PROMOTION || chessMove.getFlag() == CAPTURE_BISHOP_PROMOTION)
    {
        os << "B";
    }
    else if(chessMove.getFlag() == QUIET_ROOK_PROMOTION || chessMove.getFlag() == CAPTURE_ROOK_PROMOTION)
    {
        os << "R";
    }
    else if(chessMove.getFlag() == QUIET_QUEEN_PROMOTION || chessMove.getFlag() == CAPTURE_QUEEN_PROMOTION)
    {
        os << "Q";
    }
    return os;
}



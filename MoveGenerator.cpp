#include "MoveGenerator.h"
#include "ChessMove.h"

MoveGenerator::MoveGenerator(const ChessPosition &pChessPosition):
    chessPosition(pChessPosition)
{

}

void MoveGenerator::generate(const int &side)
{
    for(unsigned int index = a1; index < h8; index++)
    {
        if(chessPosition[index] == nullptr || ChessPosition::isOffTheBoard(index) || chessPosition[index]->getColor() != side)
        {
            continue;
        }
        // Kungsdrag
        if(chessPosition[index]->getType() == KING)
        {
            const int directions[] = {1, -1, 16, -16, 17, -17, 15, -15};
            for(unsigned int i = 0; i < 8; i++)
            {
                if(ChessPosition::isOffTheBoard(index + directions[i]))
                {
                    continue;
                }
                if(chessPosition[index + directions[i]] == nullptr)
                {
                    list.push_back(ChessMove(index, index + directions[i]));
                }
                else if(chessPosition[index + directions[i]]->getColor() != side)
                {
                    list.push_back(ChessMove(index, index + directions[i], CAPTURE_MOVE));
                }
            }
        }
        //Springardrag
        if(chessPosition[index]->getType() == KNIGHT)
        {
            const int directions[] = {31, -31, 33, -33, 18, -18, 14, -14};
            for(unsigned int i = 0; i < 8; i++)
            {
                if(ChessPosition::isOffTheBoard(index + directions[i]))
                {
                    continue;
                }
                if(chessPosition[index + directions[i]] == nullptr)
                {
                    list.push_back(ChessMove(index, index + directions[i]));
                }
                else if(chessPosition[index + directions[i]]->getColor() != side)
                {
                    list.push_back(ChessMove(index, index + directions[i], CAPTURE_MOVE));
                }
            }
        }
        // Torndrag och raka damdrag
        if(chessPosition[index]->getType() == ROOK || chessPosition[index]->getType() == QUEEN)
        {
            const int directions [] = {1, -1, 16, -16};
            for(unsigned int i = 0; i < 4; i++)
            {
                int square = index + directions[i];
                while(!ChessPosition::isOffTheBoard(square))
                {
                    if(chessPosition[square] == nullptr)
                    {
                        list.push_back(ChessMove(index, square));
                    }
                    else if(chessPosition[square]->getColor() != side)
                    {
                        list.push_back(ChessMove(index, square, CAPTURE_MOVE));
                        break;
                    }
                    else if((chessPosition[square]->getColor() == side))
                    {
                        break;
                    }
                    square += directions[i];
                }
            }
        }
        // Löpardrag och diagonala damdrag
        if(chessPosition[index]->getType() == BISHOP || chessPosition[index]->getType() == QUEEN)
        {
            const int directions [] = {17, -17, 15, -15};
            for(unsigned int i = 0; i < 4; i++)
            {
                int square = index + directions[i];
                while(!ChessPosition::isOffTheBoard(square))
                {
                    if(chessPosition[square] == nullptr)
                    {
                        list.push_back(ChessMove(index, square));
                    }
                    else if(chessPosition[square]->getColor() != side)
                    {
                        list.push_back(ChessMove(index, square, CAPTURE_MOVE));
                        break;
                    }
                    else if((chessPosition[square]->getColor() == side))
                    {
                        break;
                    }
                    square += directions[i];
                }
            }
        }
        // Bondedrag

        if(chessPosition[index]->getType() == PAWN)
        {
            if(side == WHITE)
            {
                if(chessPosition[index]->getRank() < 7 && chessPosition[index + 16] == nullptr)
                {
                   list.push_back(ChessMove(index, index + 16, QUIET_MOVE));
                   if(chessPosition[index]->getRank() == 2 && chessPosition[index + 32] == nullptr)
                   {
                       list.push_back(ChessMove(index, index + 32, DOUBLE_PAWN_MOVE));
                   }
                }
                const int directions [] = {15, 17};
                for(int i = 0; i < 2; i++)
                {
                    if(chessPosition[index]->getRank() < 7 && chessPosition[index + directions[i]] != nullptr && chessPosition[index + directions[i]]->getColor() == BLACK)
                    {
                        list.push_back(ChessMove(index, index + directions[i], CAPTURE_MOVE));
                    }
                }
                //Promovering
                if(chessPosition[index]->getRank() == 7 && chessPosition[index + 16] == nullptr)
                {
                    list.push_back(ChessMove(index, index + 16, QUIET_KNIGHT_PROMOTION));
                    list.push_back(ChessMove(index, index + 16, QUIET_BISHOP_PROMOTION));
                    list.push_back(ChessMove(index, index + 16, QUIET_ROOK_PROMOTION));
                    list.push_back(ChessMove(index, index + 16, QUIET_QUEEN_PROMOTION));
                }
                for(int i = 0; i < 2; i++)
                {
                    if(chessPosition[index]->getRank() == 7 && chessPosition[index + directions[i]] != nullptr && !ChessPosition::isOffTheBoard(index + directions[i]) && chessPosition[index + directions[i]]->getColor() == BLACK)
                    {
                        list.push_back(ChessMove(index, index + directions[i], QUIET_KNIGHT_PROMOTION));
                        list.push_back(ChessMove(index, index + directions[i], QUIET_BISHOP_PROMOTION));
                        list.push_back(ChessMove(index, index + directions[i], QUIET_ROOK_PROMOTION));
                        list.push_back(ChessMove(index, index + directions[i], QUIET_QUEEN_PROMOTION));
                    }
                }
            }
            else
            {
                if(chessPosition[index]->getRank() >= 2 && chessPosition[index - 16] == nullptr)
                {
                   list.push_back(ChessMove(index, index - 16, QUIET_MOVE));
                   if(chessPosition[index]->getRank() == 7 && chessPosition[index - 32] == nullptr)
                   {
                       list.push_back(ChessMove(index, index - 32, DOUBLE_PAWN_MOVE));
                   }
                }
                const int directions [] = {15, 17};
                for(int i = 0; i < 2; i++)
                {
                    if(chessPosition[index]->getRank() >= 2 && chessPosition[index - directions[i]] != nullptr && chessPosition[index - directions[i]]->getColor() == WHITE)
                    {
                        list.push_back(ChessMove(index, index - directions[i], CAPTURE_MOVE));
                    }
                }
                //Promovering
                if(chessPosition[index]->getRank() == 2 && chessPosition[index - 16] == nullptr)
                {
                    list.push_back(ChessMove(index, index - 16, QUIET_KNIGHT_PROMOTION));
                    list.push_back(ChessMove(index, index - 16, QUIET_BISHOP_PROMOTION));
                    list.push_back(ChessMove(index, index - 16, QUIET_ROOK_PROMOTION));
                    list.push_back(ChessMove(index, index - 16, QUIET_QUEEN_PROMOTION));
                }
                for(int i = 0; i < 2; i++)
                {
                    if(chessPosition[index]->getRank() == 2 && chessPosition[index - directions[i]] != nullptr && !ChessPosition::isOffTheBoard(index - directions[i]) && chessPosition[index - directions[i]]->getColor() == WHITE)
                    {
                        list.push_back(ChessMove(index, index + directions[i], QUIET_KNIGHT_PROMOTION));
                        list.push_back(ChessMove(index, index + directions[i], QUIET_BISHOP_PROMOTION));
                        list.push_back(ChessMove(index, index + directions[i], QUIET_ROOK_PROMOTION));
                        list.push_back(ChessMove(index, index + directions[i], QUIET_QUEEN_PROMOTION));
                    }
                }
            }
        }
    }
}

std::ostream& operator<<(std::ostream &os, const MoveGenerator &generator)
{
    os << "Lista" << std::endl;
    for(auto iterator = generator.cbegin(); iterator != generator.cend(); ++iterator)
    {
        os << *iterator << std::endl;
    }
    return os;
}


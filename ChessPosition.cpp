#include "ChessPosition.h"
#include <ostream>
#include "Defs.h"
#include <iomanip>
#include "MoveGenerator.h"
#include "ChessMove.h"
#include "Misc.h"
#include <stdio.h>
#include <string.h>

/**
 * @brief ChessPosition::ChessPosition
 */

ChessPosition::ChessPosition()
{
    squares = new ChessPiece*[128];
    for(unsigned int index = 0; index < 128; index++)
    {
        squares[index] = nullptr;
    }
    squares[a1] = new WhiteRook(a1);
    squares[b1] = new WhiteKnight(b1);
    squares[c1] = new WhiteBishop(c1);
    squares[d1] = new WhiteQueen(d1);
    squares[e1] = new WhiteKing(e1);
    squares[f1] = new WhiteBishop(f1);
    squares[g1] = new WhiteKnight(g1);
    squares[h1] = new WhiteRook(h1);

    for(unsigned int square = a2; square <= h2; square++)
    {
        squares[square] = new WhitePawn(square);
    }
    squares[a8] = new BlackRook(a8);
    squares[b8] = new BlackKnight(b8);
    squares[c8] = new BlackBishop(c8);
    squares[d8] = new BlackQueen(d8);
    squares[e8] = new BlackKing(e8);
    squares[f8] = new BlackBishop(f8);
    squares[g8] = new BlackKnight(g8);
    squares[h8] = new BlackRook(h8);

    for(unsigned int square = a7; square <= h7; square++)
    {
        squares[square] = new BlackPawn(square);
    }

    sideToMove = WHITE;
    moveGenerator = new MoveGenerator(*this);
    enPassantValue = OFF_THE_BOARD;
}

ChessPosition::ChessPosition(const std::string &fenString)
{
    squares = new ChessPiece*[128];
    for(unsigned int index = 0; index < 128; index++)
    {
        squares[index] = nullptr;
    }
    std::vector<std::string> list;
    misc::split(fenString, ' ', list);

    if(list.size() != 6)
    {
        throw std::runtime_error("Felaktig fen-sträng");
    }
    unsigned int square = a8;
    int row = 7;
    for(int index = 0; index < list[0].size(); index++)
    {
        if(ChessPosition::isOffTheBoard(square) || list[0][index] == '/')
        {
            --row;
            square = row << 4;
            continue;
        }
        if(list[0][index] == 'r')
        {
            squares[square] = new BlackRook(square);
        }
        else if(list[0][index] == 'n')
        {
            squares[square] = new BlackKnight(square);
        }
        else if(list[0][index] == 'b')
        {
            squares[square] = new BlackBishop(square);
        }
        else if(list[0][index] == 'q')
        {
            squares[square] = new BlackQueen(square);
        }
        else if(list[0][index] == 'k')
        {
            squares[square] = new BlackKing(square);
        }
        else if(list[0][index] == 'p')
        {
            squares[square] = new BlackPawn(square);
        }
        else if(list[0][index] == 'R')
        {
            squares[square] = new WhiteRook(square);
        }
        else if(list[0][index] == 'N')
        {
            squares[square] = new WhiteKnight(square);
        }
        else if(list[0][index] == 'B')
        {
            squares[square] = new WhiteBishop(square);
        }
        else if(list[0][index] == 'Q')
        {
            squares[square] = new WhiteQueen(square);
        }
        else if(list[0][index] == 'K')
        {
            squares[square] = new WhiteKing(square);
        }
        else if(list[0][index] == 'P')
        {
            squares[square] = new WhitePawn(square);
        }
        else if(list[0][index] == '2')
        {
            ++square;
        }
        else if(list[0][index] == '3')
        {
            square += 2;
        }
        else if(list[0][index] == '4')
        {
            square += 3;
        }
        else if(list[0][index] == '5')
        {
            square += 4;
        }
        else if(list[0][index] == '6')
        {
            square += 5;
        }
        else if(list[0][index] == '7')
        {
            square += 6;
        }
        ++square;
    }
    if(!(list[1] == "b" || list[1] == "w"))
    {
        throw std::runtime_error("Felaktig fen-sträng.");
    }
    if(list[1] == "w")
    {
        sideToMove = WHITE;
    }
    else
    {
        sideToMove = BLACK;
    }
    try
    {
        enPassantValue = ChessPosition::getSquareNumber(list[3]);
    }
    catch(const std::runtime_error &error)
    {
        throw;
    }
    moveGenerator = new MoveGenerator(*this);
}

ChessPosition::ChessPosition(const ChessPosition &chessPosition)
{
    squares = new ChessPiece*[128];
    memcpy(squares, chessPosition.squares, 128 * sizeof(*chessPosition.squares));
    sideToMove = chessPosition.sideToMove;
    moveGenerator = new MoveGenerator(*this);
    enPassantValue = chessPosition.enPassantValue;
}

ChessPosition::~ChessPosition()
{
    std::cout << "Destructor" << std::endl;
    delete [] squares;
    if(moveGenerator != nullptr)
    {
        delete moveGenerator;
        moveGenerator = nullptr;
    }
}

ChessPosition ChessPosition::operator=(const ChessPosition &chessPosition)
{

}

unsigned int ChessPosition::getColor(const unsigned int &index) const
{
    if(ChessPosition::isOffTheBoard(index) || squares[index] == nullptr)
    {
        return NO_COLOR;
    }
    return squares[index]->getColor();
}

void ChessPosition::makeMove(const ChessMove &chessMove)
{
    const int FROM_SQUARE = chessMove.getFromSquare();
    const int TO_SQUARE = chessMove.getToSquare();

    if(squares[TO_SQUARE] != nullptr)
    {
        delete squares[TO_SQUARE];
        squares[TO_SQUARE] = nullptr;
    }
    squares[FROM_SQUARE]->setLocation(TO_SQUARE);
    squares[TO_SQUARE] = squares[FROM_SQUARE];
    squares[FROM_SQUARE] = nullptr;
}

std::string ChessPosition::getSquareName(const unsigned int &squareIndex)
{
    if(squareIndex == OFF_THE_BOARD)
    {
        return "-";
    }

    const int FILE = (squareIndex & 7);
    const int RANK = (squareIndex >> 4);

    char file = 'a' + FILE;
    char rank = '1' + RANK;

    std::stringstream ss;
    ss << file << rank;

    return ss.str();
}

unsigned int ChessPosition::getSquareNumber(const std::string &squareName)
{
    if(squareName == "-")
    {
        return OFF_THE_BOARD;
    }

    if(squareName.length() != 2)
    {
        throw std::runtime_error("Felaktigt argument angivet.");
    }

    const int FILE_NUMBER = squareName[0] - 'a';
    const int RANK_NUMBER = squareName[1] - '0' - 1;

    if(FILE_NUMBER > 7 || RANK_NUMBER > 7)
    {
        throw std::runtime_error("Felaktigt argument angivet.");
    }

    return RANK_NUMBER * 16 + FILE_NUMBER;
}

unsigned int ChessPosition::getRank(const unsigned int &squareIndex)
{
    return (squareIndex >> 4) + 1;
}

std::ostream &operator<<(std::ostream& os, const ChessPosition &chessPosition)
{
    const unsigned int SPACE = 10;
    for(int row = 7; row >= 0; row--)
    {
        os << "\n";
        for(unsigned int column = 0; column < 16; column++ )
        {
            const int SQUARE_INDEX = row * 16 + column;
            if(ChessPosition::isOffTheBoard(SQUARE_INDEX))
            {
                continue;
            }
            const ChessPiece *chessPiece = chessPosition[SQUARE_INDEX];
            if(chessPiece == nullptr)
            {
                os << std::left << std::setw(SPACE) << "-";
            }
            else
            {
                os << std::left << std::setw(SPACE) << chessPiece->getShortName();
            }
        }
    }
    os << "--------------------------------------------------------------------------------" << std::endl
       << "Side to move: " << chessPosition.getSideToMove() << std::endl
       << "EnPassant: " << ChessPosition::getSquareName(chessPosition.getEnPassantValue()) << std::endl;
    return os;
}

#include <iostream>
#include "ChessPosition.h"
#include "MoveGenerator.h"

int main(int argc, char *argv[])
{
    try
    {
        ChessPosition *chessPosition = new ChessPosition;
        chessPosition->getMoveGenerator()->generate(WHITE);
        std::cout << *chessPosition->getMoveGenerator();

        delete chessPosition;
        chessPosition = nullptr;

    }
    catch(std::runtime_error &error)
    {
        std::cerr << error.what() << std::endl;
    }

    return 0;
}

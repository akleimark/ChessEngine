cmake_minimum_required(VERSION 3.5)

project(ChessEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ChessEngine main.cpp
ChessMove.h ChessMove.cpp
ChessPiece.h ChessPiece.cpp
ChessPosition.h ChessPosition.cpp
MoveGenerator.h MoveGenerator.cpp
Defs.h
Misc.h Misc.cpp

)


install(TARGETS ChessEngine
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

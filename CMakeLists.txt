cmake_minimum_required(VERSION 3.27)
project(bitboard_chess C)

set(CMAKE_C_STANDARD 11)

add_executable(bitboard_chess
        main.c
        helper.h
        knights.h
        kings.h
        bishop.h
        rook.h
        leaperAttacks.h
        slidingAttacks.h)
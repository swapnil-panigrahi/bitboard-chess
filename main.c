#include <stdio.h>
#include "helper.h"

int main(){
    printf("Chessboard\n");
    U64 bitboard = 0ULL;
    setBit(bitboard, E2);

    printBoard(bitboard);
    return 0;
}
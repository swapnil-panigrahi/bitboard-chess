#include "pawns.h"
#include "knights.h"
#include "leaperAttacks.h"

int main(){
    init_leapers_attack();
    for (int square = 0; square < 64; square++){
        printBoard(knight_attacks[square]);
    }
    return 0;
}
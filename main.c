#include "pawns.h"
#include "knights.h"
#include "kings.h"
#include "bishop.h"
#include "rook.h"
#include "leaperAttacks.h"

int main(){
    init_leapers_attack();
    U64 block = 0ULL;
    setBit(block, E5);
    setBit(block, D4);
    printBoard(generate_rook_attacks(D5, block));

    return 0;
}
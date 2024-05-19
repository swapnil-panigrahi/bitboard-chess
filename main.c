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
//    printf("\n");
//    printf("%d", count_bits(block));
    printf("%s", index_to_squares [least_significant_1_bit(block)]);
    return 0;
}
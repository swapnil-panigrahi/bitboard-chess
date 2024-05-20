#include "pawns.h"
#include "knights.h"
#include "kings.h"
#include "bishop.h"
#include "rook.h"
#include "leaperAttacks.h"

int main(){
    init_leapers_attack();
//    U64 block = 0ULL;
//    setBit(block, E5);
//    setBit(block, D4);
//    printBoard(generate_rook_attacks(D5, block));
//    printf("\n");
//    printf("%d", count_bits(block));
//    printf("%s", index_to_squares [least_significant_1_bit(block)]);
    U64 attack_mask_rook = mask_rook_attacks(A1);
    for(int i=0;i<4096;i++){
        U64 occupancy = set_occupancy(i, count_bits(attack_mask_rook) , attack_mask_rook);
        printBoard(occupancy);
    }
    return 0;
}
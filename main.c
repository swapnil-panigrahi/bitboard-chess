#include "pawns.h"
#include "knights.h"
#include "kings.h"
#include "bishop.h"
#include "rook.h"
#include "leaperAttacks.h"
#include "slidingAttacks.h"

int main(){
    init_leapers_attack();
//    for(int i = 0;i < 8; i++){
//        for(int j = 0;j < 8; j++){
//            int square = i * 8 + j;
//            printf("%d,", count_bits(mask_bishop_attacks(square)));
//        }
//        printf("\n");
//    }
    printf("%ud\n",random_number_XORShift());
    printf("%ud\n",random_number_XORShift());
    printBoard(random_number_64bits());
    printBoard(magic_number_candidate());
    return 0;
}
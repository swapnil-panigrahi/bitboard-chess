#include "pawns.h"
#include "knights.h"
#include "kings.h"
#include "bishop.h"
#include "rook.h"
#include "leaperAttacks.h"

int main(){
    init_leapers_attack();
    printBoard(mask_rook_attacks(A8));

    return 0;
}
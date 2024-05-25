const U64 not_A = 18374403900871474942ULL;
const U64 not_H = 9187201950435737471ULL;

U64 pawn_attacks[2][64];
U64 mask_pawn_attacks(int side, int square){
    U64 attacks = 0ULL;
    U64 board = 0ULL;

    setBit(board, square);

    if (!side){
        //White pawns
        if ((board >> 7) & not_A){
            attacks |= (board >> 7);
        }
        if ((board >> 9) & not_H){
            attacks |= (board >> 9);
        }
    }
    else{
        //Black pawns
        if ((board << 7) & not_H){
            attacks |= (board << 7);
        }
        if ((board << 9) & not_A){
            attacks |= (board << 9);
        }
    }
    return attacks;
}
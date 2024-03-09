U64 king_attacks[64];
U64 mask_king_attacks(int square){
    U64 attacks = 0ULL;
    U64 board = 0ULL;

    setBit(board, square);

    if (board >> 8){
        attacks |= (board >> 8);
    }
    if ((board >> 9) & not_H){
        attacks |= (board >> 9);
    }
    if ((board >> 7) & not_A){
        attacks |= (board >> 7);
    }
    if ((board >> 1) & not_H){
        attacks |= (board >> 1);
    }
    if ((board << 8)){
        attacks |= (board << 8);
    }
    if ((board << 9) & not_A){
        attacks |= (board << 9);
    }
    if ((board << 7) & not_H){
        attacks |= (board << 7);
    }
    if ((board << 1) & not_A){
        attacks |= (board << 1);
    }

    return attacks;
}
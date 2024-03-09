const U64 not_HG = 4557430888798830399ULL;
const U64 not_AB = 18229723555195321596ULL;

U64 knight_attacks[64];
U64 mask_knight_attacks(int square){
    U64 attacks = 0ULL;
    U64 board = 0ULL;

    setBit(board, square);

    if ((board >> 17) & not_H){
        attacks |= (board >> 17);
    }
    if ((board >> 15) & not_A){
        attacks |= (board >> 15);
    }
    if ((board >> 10) & not_HG){
        attacks |= (board >> 10);
    }
    if ((board >> 6) & not_AB){
        attacks |= (board >> 6);
    }
    if ((board << 17) & not_A){
        attacks |= (board << 17);
    }
    if ((board << 15) & not_H){
        attacks |= (board << 15);
    }
    if ((board << 10) & not_AB){
        attacks |= (board << 10);
    }
    if ((board << 6) & not_HG){
        attacks |= (board << 6);
    }

    return attacks;
}
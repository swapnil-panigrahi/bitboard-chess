const U64 not_HG = 4557430888798830399ULL;
const U64 not_AB = 18229723555195321596ULL;

U64 knight_attacks[64];
U64 mask_knight_attacks(int square){
    U64 attacks = 0ULL;
    U64 bitboard = 0ULL;

    setBit(bitboard, square);

    if ((bitboard >> 17) & not_H){
        attacks |= (bitboard >> 17);
    }
    if ((bitboard >> 15) & not_A){
        attacks |= (bitboard >> 15);
    }
    if ((bitboard >> 10) & not_HG){
        attacks |= (bitboard >> 10);
    }
    if ((bitboard >> 6) & not_AB){
        attacks |= (bitboard >> 6);
    }
    if ((bitboard << 17) & not_A){
        attacks |= (bitboard << 17);
    }
    if ((bitboard << 15) & not_H){
        attacks |= (bitboard << 15);
    }
    if ((bitboard << 10) & not_AB){
        attacks |= (bitboard << 10);
    }
    if ((bitboard << 6) & not_HG){
        attacks |= (bitboard << 6);
    }

    return attacks;
}
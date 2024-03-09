#include "helper.h"

const U64 not_A = 18374403900871474942ULL;
const U64 not_H = 9187201950435737471ULL;

U64 pawn_attacks[2][64];
U64 mask_pawn_attacks(int side, int square){
    U64 attacks = 0ULL;
    U64 bitboard = 0ULL;

    setBit(bitboard, square);

    if (!side){
        //White pawns
        if ((bitboard >> 7) & not_A){
            attacks |= (bitboard >> 7);
        }
        if ((bitboard >> 9) & not_H){
            attacks |= (bitboard >> 9);
        }
    }
    else{
        //Black pawns
        if ((bitboard << 7) & not_H){
            attacks |= (bitboard << 7);
        }
        if ((bitboard << 9) & not_A){
            attacks |= (bitboard << 9);
        }
    }
    return attacks;
}
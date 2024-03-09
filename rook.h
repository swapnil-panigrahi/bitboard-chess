U64 mask_rook_attacks(int square){
    U64 attacks = 0ULL;
    int rank, file;
    int target_rank = square/8;
    int target_file = square%8;

    for (rank = target_rank+1; rank<=6; rank++){
        attacks |= (1ULL << (rank*8 + target_file));
    }
    for (rank = target_rank-1; rank>=1; rank--){
        attacks |= (1ULL << (rank*8 + target_file));
    }
    for (file = target_file+1; file<=6; file++){
        attacks |= (1ULL << (target_rank*8 + file));
    }
    for (file = target_file-1; file>=1; file--){
        attacks |= (1ULL << (target_rank*8 + file));
    }

    return attacks;
}
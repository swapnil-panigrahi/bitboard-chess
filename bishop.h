U64 mask_bishop_attacks(int square){
    U64 attacks = 0ULL;
    int rank, file;
    int target_rank = square/8;
    int target_file = square%8;

    for (rank = target_rank+1, file = target_file+1; rank<=6 && file<=6; rank++, file++){
        attacks |= (1ULL << (rank*8 + file));
    }
    for (rank = target_rank-1, file = target_file+1; rank>=1 && file<=6; rank--, file++){
        attacks |= (1ULL << (rank*8 + file));
    }
    for (rank = target_rank+1, file = target_file-1; rank<=6 && file>=1; rank++, file--){
        attacks |= (1ULL << (rank*8 + file));
    }
    for (rank = target_rank-1, file = target_file-1; rank>=1 && file>=1; rank--, file--){
        attacks |= (1ULL << (rank*8 + file));
    }

    return attacks;
}

U64 generate_bishop_attacks(int square, U64 block){
    U64 attacks = 0ULL;
    int rank, file;
    int target_rank = square/8;
    int target_file = square%8;

    for (rank = target_rank+1, file = target_file+1; rank<=7 && file<=7; rank++, file++){
        attacks |= (1ULL << (rank*8 + file));
        if ((1ULL << (rank*8 + file)) & block) break;
    }
    for (rank = target_rank-1, file = target_file+1; rank>=0 && file<=7; rank--, file++){
        attacks |= (1ULL << (rank*8 + file));
        if ((1ULL << (rank*8 + file)) & block) break;
    }
    for (rank = target_rank+1, file = target_file-1; rank<=7 && file>=0; rank++, file--){
        attacks |= (1ULL << (rank*8 + file));
        if ((1ULL << (rank*8 + file)) & block) break;
    }
    for (rank = target_rank-1, file = target_file-1; rank>=0 && file>=0; rank--, file--){
        attacks |= (1ULL << (rank*8 + file));
        if ((1ULL << (rank*8 + file)) & block) break;
    }

    return attacks;
}
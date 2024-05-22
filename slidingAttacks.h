const int occupancy_bits_bishop[64]={
        6,5,5,5,5,5,5,6,
        5,5,5,5,5,5,5,5,
        5,5,7,7,7,7,5,5,
        5,5,7,9,9,7,5,5,
        5,5,7,9,9,7,5,5,
        5,5,7,7,7,7,5,5,
        5,5,5,5,5,5,5,5,
        6,5,5,5,5,5,5,6
};

const int occupancy_bits_rook[64]={
        12,11,11,11,11,11,11,12,
        11,10,10,10,10,10,10,11,
        11,10,10,10,10,10,10,11,
        11,10,10,10,10,10,10,11,
        11,10,10,10,10,10,10,11,
        11,10,10,10,10,10,10,11,
        11,10,10,10,10,10,10,11,
        12,11,11,11,11,11,11,12
};

U64 set_occupancy (int index, int bits, U64 mask){
    U64 occupancy = 0ULL;
    for(int count=0;count<bits;count++){
        int square = least_significant_1_bit(mask);
        resetBit(mask, square);
        if(index & (1 << count)){
            occupancy |= (1ULL << square);
        }
    }
    return occupancy;
}


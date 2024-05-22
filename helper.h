#include <stdio.h>

#define U64 unsigned long long
#define getBit(board,square) (board & (1ULL<<square))
#define setBit(board,square) (board |= (1ULL<<square))
#define resetBit(board,square) (getBit(board,square) ? board ^= (1ULL<<square) : 0)

enum {
    white,
    black
};
enum {
    A8, B8, C8, D8, E8, F8, G8, H8,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A1, B1, C1, D1, E1, F1, G1, H1
};

const char *index_to_squares[] = {
        "A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8",
        "A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7",
        "A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6",
        "A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5",
        "A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4",
        "A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3",
        "A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2",
        "A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1"
};

unsigned int state = 1804289383;

// print board
void printBoard(U64 board){
    printf("Bitboard: %llud\n\n", board); //Bitboard numeric for getting some constants etc.
    for (int rank=0; rank<8; rank++){
        printf(" %d ", 8-rank);
        for (int file=0; file<8; file++){
            int square = rank*8 + file;
            printf(" %d", getBit(board,square) ? 1 : 0);
        }
        printf("\n");
    }
    // just padding, ignore
    printf("    ");
    for (int i=65; i<73; i++){
        printf("%c ", i);
    }
}

int count_bits(U64 board){
    int count = 0;
    while (board>0){
        count++;
        board &= board - 1;
    }
    return count;
}

int least_significant_1_bit(U64 board){
    if(board>0){
        return count_bits((board & -board)-1);
    }
    else{
        return -1;
    }
}

unsigned int random_number_XORShift(){
    unsigned int num = state;
    num ^= num << 13;
    num ^= num >> 17;
    num ^= num << 5;
    state = num;
    return num;
}

U64 random_number_64bits(){
    U64 number1, number2, number3, number4;
    number1 = (U64)(random_number_XORShift() & 0xFFFF);
    number2 = (U64)(random_number_XORShift() & 0xFFFF);
    number3 = (U64)(random_number_XORShift() & 0xFFFF);
    number4 = (U64)(random_number_XORShift() & 0xFFFF);

    return number1 | (number2 << 16) | (number3 << 32) | (number4 << 48);
}

U64 magic_number_candidate(){
    return random_number_64bits() & random_number_64bits() & random_number_64bits();
}
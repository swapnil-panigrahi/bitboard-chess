#include <stdio.h>
#include "bishop.h"
#include "rook.h"
#include "slidingAttacks.h"
#include <string.h>

#define U64 unsigned long long
#define getBit(board,square) (board & (1ULL<<square))
#define setBit(board,square) (board |= (1ULL<<square))
#define resetBit(board,square) (getBit(board,square) ? board ^= (1ULL<<square) : 0)

#define empty_board "8/8/8/8/8/8/8/8 w - - "
#define start_position "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 "
#define tricky_position "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1 "
#define killer_position "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1"
#define cmk_position "r2q1rk1/ppp2ppp/2n1bn2/2b1p3/3pP3/3P1NPP/PPP1NPB1/R1BQ1RK1 b - - 0 9 "

static inline int countBit(U64 board){
    int count = 0;
    while (board){
        count++;
        board &= board - 1;
    }

    return count;
}

enum { white, black, both };

enum { rook, bishop };

enum {
    A8, B8, C8, D8, E8, F8, G8, H8,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A1, B1, C1, D1, E1, F1, G1, H1, None
};

enum { WK = 1, WQ = 2, BK = 4, BQ = 8 };

enum { P, N, B, R, Q, K, p, n, b, r, q, k };

char ascii_pieces[12] = "PNBRQKpnbrqk";
char *unicode_pieces[12] = {"♙","♘","♗","♖","♕","♔","♟","♞","♝","♜","♛","♚"};

int char_pieces[] = {
        ['P']=P,
        ['N']=N,
        ['B']=B,
        ['R']=R,
        ['Q']=Q,
        ['K']=K,
        ['p']=p,
        ['n']=n,
        ['b']=b,
        ['r']=r,
        ['q']=q,
        ['k']=k
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

U64 bitboards[12];
U64 occupancies[3];

int side = 0;
int enpassant = None;
int castle = 0;

// print board
void printBitboard(U64 board){
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

void printBoard(){
    printf("\n");
    for (int rank = 0; rank < 8; rank++){
        for (int file = 0; file < 8; file++){
            int square = rank * 8 + file;

            if (!file){
                printf(" %d ", 8 - rank);
            }
            int piece = -1;
            for (int _piece = P; _piece <= k; _piece++){
                if (getBit(bitboards[_piece], square)){
                    piece = _piece;
                }
            }

            printf(" %c", (piece == -1) ? '.' : ascii_pieces[piece]);
        }
        printf("\n");
    }
    printf("    A B C D E F G H\n");
    printf("Side : %c\n", !side ? 'W' : 'B');
    printf("Enpassant : %s\n", (enpassant != None) ? index_to_squares[enpassant] : "No");
    printf("Castling : %c%c%c%c\n\n", (castle & WK) ? 'K' : '-', (castle & WQ) ? 'Q' : '-', (castle & BK) ? 'k' : '-', (castle & BQ) ? 'q' : '-');
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
    if(board){
        return count_bits((board & -board)-1);
    }
    else{
        return -1;
    }
}

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

unsigned int state = 1804289383;

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

void parseFEN(char* fen){
    memset(bitboards, 0ULL, sizeof(bitboards));
    memset(occupancies, 0ULL, sizeof(occupancies));

    side = 0; castle = 0; enpassant = None;

    for (int rank = 0; rank < 8; rank++){
        for (int file = 0; file < 8; file++){
            int square = rank * 8 + file;
            if ((*fen >= 'a' && *fen <= 'z') || *fen >= 'A' && *fen <= 'Z'){
                int piece = char_pieces[*fen];

                setBit(bitboards[piece], square);
                *fen++;
            }

            if (*fen >= '0' && *fen <= '9'){
                int piece = -1;
                for (int _piece = P; _piece <= k; _piece++){
                    if (getBit(bitboards[_piece], square)){
                        piece = _piece;
                    }
                }
                if (piece == -1) file--;
                file += (*fen - '0');
                *fen++;
            }

            if (*fen == '/'){
                *fen++;
            }
        }
    }
    *fen++;
    if (*fen == 'w') side = white;
    else side = black;

    fen+=2;

    if (*fen == 'K'){
        castle |= WK;
        *fen++;
    }
    if (*fen == 'Q'){
        castle |= WQ;
        *fen++;
    }
    if (*fen == 'k'){
        castle |= BK;
        *fen++;
    }
    if (*fen == 'q'){
        castle |= BQ;
        *fen++;
    }
    if (*fen == '-') *fen++;

    *fen++;
    if (*fen != '-'){
        int file = fen[0] - 'a';
        int rank = 8 - (fen[1] - '0');

        enpassant = rank * 8 + file;
    }
    else enpassant = None;

    for (int piece = P; piece <= K; piece++){
        occupancies[white] |= bitboards[piece];
    }
    for (int piece = p; piece <= k; piece++){
        occupancies[black] |= bitboards[piece];
    }

    occupancies[both] |= occupancies[white];
    occupancies[both] |= occupancies[black];
}
U64 magic_number(int square, int relevant_bits, int bishop){
    U64 occupanciess[4096];
    U64 attacks[4096];
    U64 used_attacks[4096];
    U64 attack_mask = bishop ? mask_bishop_attacks(square) : mask_rook_attacks(square);
    int occupancy_bits = 1 << relevant_bits;
    for(int i=0;i<occupancy_bits;i++){
        occupanciess[i]= set_occupancy(i,relevant_bits,attack_mask);
        attacks[i] = bishop ? generate_bishop_attacks(square,occupanciess[i]) : generate_rook_attacks(square,occupanciess[i]);
    }
}

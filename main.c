#define U64 unsigned long long

#include "helper.h"
#include "pawns.h"
#include "knights.h"
#include "kings.h"
#include "leaperAttacks.h"

int main(){
    init_leapers_attack();
    for (int position = A2; position < A1; position++){
        setBit(bitboards[P], position);
    }
    for (int position = A7; position < A6; position++){
        setBit(bitboards[p], position);
    }
    setBit(bitboards[N], B1);
    setBit(bitboards[N], G1);

    setBit(bitboards[R], A1);
    setBit(bitboards[R], H1);

    setBit(bitboards[B], C1);
    setBit(bitboards[B], F1);

    setBit(bitboards[Q], D1);
    setBit(bitboards[K], E1);

    setBit(bitboards[n], B8);
    setBit(bitboards[n], G8);

    setBit(bitboards[r], A8);
    setBit(bitboards[r], H8);

    setBit(bitboards[b], C8);
    setBit(bitboards[b], F8);

    setBit(bitboards[q], D8);
    setBit(bitboards[k], E8);

    parseFEN("r2q1rk1/ppp2ppp/2n1bn2/2b1p3/3pP3/3P1NPP/PPP1NPB1/R1BQ1RK1 b Kk e6 0 9 ");
    printBoard();
    return 0;
}
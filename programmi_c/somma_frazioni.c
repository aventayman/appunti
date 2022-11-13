#include <stdio.h>

int MCD (int a, int b) {
    int resto;
    while (a % b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    return b;
}

void somma_frazioni(int n1, int d1, int n2, int d2, int *nr, int *dr) {
    *nr = n1 * d2 + n2 * d1;
    *dr = d1 * d2;
    int M = MCD(*nr, *dr);
    *nr /= M;
    *dr /= M;
}

int main() {
    int n, d;
    somma_frazioni(2, 3, 4, 5, &n, &d);
    return 0;
}

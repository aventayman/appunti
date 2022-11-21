#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 100

void convoluzione(int m[][N], int k[][3], int r, int filtrata[][N])
{
    //Due cicli for per elaborare la matrice originale
    for (int i = 1; i < r - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            //Parte che fa la somma pesata centrata in i, j
            int somma = 0;
            for (int l = -1; l < 2; l++) {
                for (int n = -1; n < 2; n++) {
                    somma += m[i + l][j + n] * k[l + 1][n + 1];
                }
            }
            filtrata[i][j] = somma;
        }
    }
}
    
int main() {
    
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
    
#define RIGHE 4
#define COLONNE 5

int main() {
    int m[RIGHE][COLONNE];
    for (int i = 0; i < RIGHE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            m[i][j] = rand()%100;
        }
    }
    for (int i = 0; i < RIGHE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            printf("%4d", m[i][j]);
        }
        printf("\n");
    }

    //valori degli indici validi
    int i, j;
    i = 3;
    j = 2;
    printf("m[%d][%d] = %d\n", i, j, m[i][j]);
    //Valori della colonna al di fuori del range
    i = 1;
    j = 7;
    printf("m[%d][%d] = %d\n", i, j, m[i][j]);
    //Valori della riga al di fuori del range
    i = 525;
    j = 3;
    printf("m[%d][%d] = %d\n", i, j, m[i][j]);
    return 0;
}

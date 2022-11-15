#include <stdio.h>
#include <math.h>
#include <stdlib.h>
    
#define RIGHE 4
#define COLONNE 5

int main() {
    int m[RIGHE][COLONNE];
    int principale = 0, secondaria = 0;
    for (int i = 0; i < RIGHE; i++) {
        for (int j = 0; j < COLONNE; j++) {
            m[i][j] = rand()%100;
        }
    }
    //Calcolo del valore della diagonale principale
    for (int i = 0; i < RIGHE; i++) {
        principale += m[i][i];
    }
    //Calcolo del valore della diagonale secondaria
    for (int i = 0; i < RIGHE; i++) {
        secondaria += m[i][COLONNE - i - 1];
    }
    return 0;
}

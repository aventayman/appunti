#include <stdio.h>
#include <math.h>
#include <stdlib.h>
    
#define RIGHE 10
#define COLONNE 30

int cerca_in_vettore(int v[], int r, int n)
{
    int quanti = 0;
    for (int i = 0; i < r; i++) {
        if (v[i] == n) {
            quanti++;
        }
    }
    return quanti;
}

void conta_valori(int m[][COLONNE], int v[], int r, int n)
{
    //Scorro tutte le righe della matrice
    for (int i = 0; i < r; i++) {
        //Per ogni riga uso la funzione definita sopra per contare
        //quante volte il valore n compare in quella riga
        v[i] = cerca_in_vettore(m[i], COLONNE, n);
    }
}

int main() {
    int v[RIGHE], m[RIGHE][COLONNE];

    //Supponendo di aver riempito la matrice con dei valori
    conta_valori(m, v, RIGHE, 24);
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 100

int lancio_dado(int n)
{
    return rand() % n + 1;

}

int lancio_dadi(int k, int n)
{
    int totale = 0;
    for (int i = 0; i < k; ++i) {
        totale += lancio_dado(n);
    }
    return totale;
}

void azzera(int v[], int n)
{
    for (int i = 0; i < n; i++) {
        v[i] = 0;
    }
}

void simulazione(int v[], int k, int n, int n_lanci)
{
   for (int i = 0; i < n_lanci; ++i) {
       int valore = lancio_dadi(k, n);
       v[valore]++;
   }
}

void disegna_istogramma(int v[], int prima, int ultima, int max_asterischi)
{
    int massimo = v[prima];
    for (int i = 0; i < ultima; ++i) {
        if (v[i] > massimo) {
            massimo = v[i];
        }
    }
    //Ciclo esterno per visitare tutte le colonne
    for (int i = prima; i <= ultima; ++i) {
        printf("%4d -> ", i);
        //Disegno della singola colonna i-esima
        int asterischi = (((float)v[i])/massimo)*max_asterischi;
        for (int j = 0; j < asterischi; ++j) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int lanci[MAX]; //Contiene il conteggio dei lanci per ogni valore
    azzera(lanci, MAX);
    simulazione(lanci, 2, 12, 100000);
    for (int i = 2; i <= 12; ++i) {
        printf("%d %d\n", i, lanci[i]);
    }
    disegna_istogramma(lanci, 2, 12, 30);
    return 0;
}

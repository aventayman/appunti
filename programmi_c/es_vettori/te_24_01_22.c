#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 1000
    
int main() {
    int v[MAX];
    int N, a, b;
    printf("Inserisci il numero di elementi (10-1000): ");
    scanf("%d", &N);
    while (N < 10 || N > 1000) {
        printf("Il numero inserito deve essere compreso tra 10 e 1000: ");
        scanf("%d", &N);
    }
    printf("Inserisci i valori di a e b: ");
    scanf("%d", &a);
    scanf("%d", &b);
    for (int i = a; i <= b; i++) {
        for (int j = i + 1; j <= b; j++) {
            if (v[i] * v[j] == 42) {
                printf("Almeno una coppia ha come prodotto 42\n");
                return 0;
            }
        }
    }
    printf("Non esiste nemmeno una coppia il cui prodotto è 42\n");
    return 0;
}

#include <stdio.h>

#define MAX 100

int main() {
    int valori[MAX];
    int N;
    printf("Quanti valori vuoi inserire (<=100): ");
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        printf("Inserisci un valore: ");
        scanf("%d", &valori[i]);
    }
    for (int i; i < N; i++) {
        if (valori[i] % 2 == 0) {
            printf("%d\n", valori[i]);
        }
    }
    for (int i = 0; i < N; i++) {
        if (valori[i] % 2 == 1) {
            printf("%d\n", valori[i]);
        }
    }
    return 0;
}

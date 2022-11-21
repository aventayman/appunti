#include <stdio.h>
#include <math.h>
#include <stdlib.h>
    
#define N 3
#define M 4

int massimo(int m[][M], int n) {
    int temp = m[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            if (m[i][j] > temp) {
                temp = m[i][j];
            }
        }
    }
    return temp;
}

void inizializza_matrice(int m[][M], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < M; j++) {
            m[i][j] = rand()%100;
        }
    }
}

int main() {
    int m[N][M];
    inizializza_matrice(m, N);
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 4
#define M 3
    
int main() {
    int m[N][M], t[M][N];
    //Inserisco dei valori in m
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            m[i][j] = rand()%100;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            t[j][i] = m[i][j];
        }
    }

    //Cosa succede dovendo fare la rotazione "sul posto"
    //Così non andrebbe bene
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            t[j][i] = m[i][j];
        }
    }
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Calcola il fattoriale di un numero
int fact(int n){
    if (n == 0)
        return 1;
    for (int i = 1; i < n; i++) {
        n *= i;
    }
    return n;
}

//Eleva un numero ad un altro
double elevato(double x, int n){
    int p = x;
    for (int i = 1; i < n; i++) {
        x *= p;
    }
    return x;
}

//Calcola la sommatoria per l'arccos
double calcolare_somma(double x, int n){
    double risultato = 3.1415/2;
    for (int i = 0; i <= n; i++) {
        risultato -= (fact(2 * i) * elevato(x, 2 * i + 1))/(elevato(4, i) * elevato(fact(i), 2) * (2 * i + 1));
    }
    return risultato;
}

int main() {
    double x;
    int n;
    
    printf("Inserire il valore x su cui si vuole calcolare arccos(x): ");
    scanf("%lf", &x);
    while (x < -1 || x > 1) scanf("%lf", &x);
    
    printf("Inserire la precisione: ");
    scanf("%d", &n);
    while (n < 1) scanf("%d", &n);

    printf("arccos(%lf) = %lf \n", x, calcolare_somma(x, n));
    printf("Il valore di arccos calcolato dalla libreria è: %lf \n", acos(x));

    return 0;
}

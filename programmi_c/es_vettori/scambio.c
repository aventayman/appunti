#include <stdio.h>

void scambio (int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

// Effettuare lo scambio di due variabili
// a contiene l'indirizzo di memoria della prima variabile
// b contiene l'indirizzo di memoria della seconda variabile

void scambio_vero(int*a, int*b) {
    //Questa scrittura va letta come assegna a temp il valore
    //contenuto all'indirizzo memoriazzato dentro a
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 5, b = 7;
    //Usando il simbolo & davanti a una variabile si intende di leggere
    //il suo indirizzo
    scambio_vero(&a, &b);
    printf("indirizzo di a: %p\nindirizzo di b: %p", &a, &b);
    return 0;
}

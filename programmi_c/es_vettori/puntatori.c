#include <stdio.h>
#include <math.h>
#include <stdlib.h>
    
int main() {
    int *p, v[10];
    //Inizialmente nessuna delle due variabili, p e v, è inizializzata,
    //però mentre p contiene un valore "casuale", il vettore v contiene 
    //10 valori indeterminati, ma l'indirizzo di v è valido
    //printf("%p %p\n", p, v);
    //Questa istruzione non è corretta perché p contiene un indirizzo
    //non inizializzato
    //printf("%d %d", *p, v[0]);
    //Se voglio inizializzare p devo assegnargli u indirizzo valido
    // p = 7; //Non si può assegnare un valore scelto da noi
    //printf("%d %d", *p, v[0]);
    //Se voglio inizializzare p devo assegnargli un indirizzo valido
    p = v; //Valida, in questo momento p e v sono "sinonimi" o "alias"
    printf("%d %d\n", *p, v[0]); //In questo momento sono equivalenti
    v[0] = 42;
    printf("%d %d \n", *p, v[0]);
    //L'aritmetica dei puntatori prevede che si possano fare somme e differenze
    for (int i = 0; i < 10; ++i) {
        v[i] = rand()%100;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d %d\n", *(p + i), v[i]);
    }
    p = &v[5];
    for (int i = 0; i < 4; i++) {
        printf("%d\n", *(p + i));
    }
    p = v;
    while (p < &v[9]) {
        printf("%d\n", *p);
        p++;
    }
    p--;
    while (p >= &v[0]) {
        printf("%d \n", *p);
        p--;
    }
    int *s;
    s = p;
    p--;
    while (p >= &v[0]) {
        printf("%d \n", *p);
        p--;
    }
    printf("%d\n", s - p);
    return 0;
}

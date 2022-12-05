#ifndef COMPLESSI_H
#define COMPLESSI_H

typedef struct {
    float re;
    float im;
}Complesso;

typedef struct {
    float modulo;
    float fase;
}ComplessoExp;

float modulo(Complesso c); //Firma della funzione

ComplessoExp convertiInExp(Complesso a);

Complesso convertiInComplesso(ComplessoExp a);

void stampa( Complesso c);

void stampaExp( ComplessoExp c);

Complesso coniugato(Complesso c);

Complesso reciproco(Complesso c);

Complesso somma(Complesso a, Complesso b);

Complesso differenza(Complesso a, Complesso b);

Complesso prodotto(Complesso a, Complesso b);

Complesso rapporto(Complesso a, Complesso b);

#endif //COMPLESSI_H

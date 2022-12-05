#include <stdio.h>

#define H   5
#define W   5

typedef struct{
    char m[H][W];
} Schermo;

typedef struct {
    int x;
    int y;
    Schermo s;
} OggettoV1;

typedef struct{
    int x;
    int y;
    Schermo *s;
}OggettoV2;

void stampa_schermo(Schermo s){
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            printf("%c", s.m[i][j]);
        }
        printf("\n");
    }
}

void metti_a_schermo(OggettoV1 o){
    o.s.m[o.x][o.y] = 'x';
}

//Il passaggio per indirizzo in questo caso è obbligatorio
//perché si vuole modificare l'oggetto passato
void metti_a_schermoV2(OggettoV2 *o){
    o->s->m[o->x][o->y] = 'x';
}

void metti_a_schermo_per_indirizzo(OggettoV1 *o){
    o->s.m[o->x][o->y] = 'x';
}

int main() {
    OggettoV1 o1, o2;
    o1.x = 2;
    o1.y = 3;
    Schermo schermo;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            schermo.m[i][j] = '.';
        }
    }
    o1.s = schermo;
    //stampa_schermo(schermo);
    //stampa_schermo(o1.s);
    //Attenzione che schermo e o1.s, poiché c'è l'assegnamento sono due cose diverse
    //La chiamata di questa funzione lavora su una copia di o1,
    //quindi lo schermo non si aggiorna;
    //metti_a_schermo(o1);
    //stampa_schermo(o1.s);
    metti_a_schermo_per_indirizzo(&o1); 
    //stampa_schermo(o1.s);
    o2 = o1;
    //stampa_schermo(o2.s);
    o2.x = 4;
    o2.y = 1;
    metti_a_schermo_per_indirizzo(&o2);
    //stampa_schermo(o2.s);
    OggettoV2 o3, o4;
    o3.x = 2;
    o3.y = 2;
    o3.s = &schermo;
    metti_a_schermoV2(&o3);
    //stampa_schermo(schermo);
    o4 = o3;
    o4.x = 1;
    o4.y = 1;
    metti_a_schermoV2(&o4);
    //stampa_schermo(schermo);
    stampa_schermo(*o3.s);
    return 0;
}

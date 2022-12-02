#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Definisco un nuovo tipo di dato a disposizione di qualsiasi parte del programma 
typedef struct {
    float x;
    float y;
} Punto2D;

typedef struct {
    Punto2D v1;
    Punto2D v2;
    Punto2D v3;
} Triangolo;

typedef struct {
    Punto2D vertici[4];
} Pentagono;

#define MAX_VERTICI 1000

typedef struct {
    Punto2D vertici[MAX_VERTICI];
    int n_vertici;
} Poligono;

float distanza(Punto2D p1, Punto2D p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

float calcola_perimetro(Poligono p) {
    float perimetro = 0;
    for (int i = 0; i < p.n_vertici; i++) {
        Punto2D a = p.vertici[i];
        Punto2D b = p.vertici[(i+1)%p.n_vertici];
        perimetro += distanza(a, b);
    }

    return perimetro;
}

int main() {
    //Definisco delle variabili locali in un certo modo
    struct  {
        float x;
        float y;
    } p; //Nome della variabile di tipo struttura appena definita
    
    p.x = 7.4; //Si legge: il valore 7.4 viene assegnato all'attributo x di p
    p.y = 4.3;
    //Così non si può fare p = 7.4;
    //Anche per l'I/O si ragiona in termini degli attributi elementari
    //scanf("%f", &p.x);
    printf("x:%f y:%f\n", p.x, p.y);

    //Da qui usiamo la struttura generale definita all'inizio del programma
    //Dichiaro una variabile di tipo Punted
    Punto2D p1, p2;
    p1.x = p1.y = 0;

    //Tutte le operazioni relazionali non sono valide per le strutture
    //if (p1 > p2)  NO
    //L'unica operazione elementare valida tra strutture è la copia
    p2 = p1;

    printf("p1: %f, %f p2: %f, %f\n", p1.x, p1.y, p2.x, p2.y);

    Triangolo t;
    t.v1.x = 1.2;
    t.v1.y = 2.4;

    t.v2 = p1;
    t.v3.x = 3.4;
    t.v3.y = 2.8;

    Pentagono pentagono;
    
    for (int i = 0; i < 5; i++) {
        pentagono.vertici[i].x = rand()%100;
        pentagono.vertici[i].y = rand()%100;
    }
    float perimetro = 0;
    //Calcola il perimetro di questo ipotetico pentagono
    for (int i = 0; i < 5; i++) {
        Punto2D a = pentagono.vertici[i];
        Punto2D b = pentagono.vertici[(i+1)%5];
        perimetro += distanza(a, b);
    }
    
    Poligono dodecagono;
    dodecagono.n_vertici = 12;

    for (int i = 0; i < dodecagono.n_vertici; i++) {
        dodecagono.vertici[i].x = rand()%100;
        dodecagono.vertici[i].y = rand()%100;
    }

    perimetro = calcola_perimetro(dodecagono);

    return 0;
}

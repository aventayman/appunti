//Esercizio riassuntivo di tutta la parte di programmazione
//Programma per la gestione di esami universitari

#include <stdio.h>
#include <string.h>

#define MATERIA         30
#define LEN_STRINGHE    50
#define MAX_ESAMI       60
#define MAX_STUDENTI    200

typedef struct {
    int g;
    int m;
    int a;
} Data;

typedef struct {
    char materia[MATERIA];
    int voto;
    Data data;
} Esame;

typedef struct {
    char nome[LEN_STRINGHE];
    char cognome[LEN_STRINGHE];
    char matricola[LEN_STRINGHE];
    Esame esami[MAX_ESAMI];
    int numero_esami;
} Studente;

typedef struct {
    char nome[LEN_STRINGHE];
    Studente studenti[MAX_STUDENTI];
    int numero_studenti;
} CorsoDiStudi;

void menu() {
    printf("1 - Aggiungi un nuovo studente\n");
    printf("2 - Aggiungi un esame a uno studente\n");
    printf("3 - Stampa passati di un certo esame\n");
    printf("4 - Stampa la media di un certo studente\n");
    printf("0 - Esci\n");
}

void aggiungi_studente(CorsoDiStudi *c, Studente s) {
    c->studenti[c->numero_studenti] = s;
    c->numero_studenti++;
}

void stampa_studente(Studente s) {
    printf("Matricola: %s Nominativo %s %s\n", s.matricola, s.cognome, s.nome);
}

void stampa_corso(CorsoDiStudi c) {
    printf("Corso di %s\n", c.nome);
    printf("Numero studenti iscritti: %d\n", c.numero_studenti);
    printf("Elenco degli studenti:\n");
    for (int i = 0; i < c.numero_studenti; i++) {
        stampa_studente(c.studenti[i]);
    }
}

void aggiungi_esame(CorsoDiStudi *c, char matricola[]){
    Esame nuovo;
    printf("Inserisci il nome dell'esame: ");
    scanf("%s", nuovo.materia);
    printf("Inserisci il voto: ");
    scanf("%d", &nuovo.voto);
    printf("Inserisci la data dell'esame (gg/mm/aaaa): ");
    scanf("%d/%d/%d", &nuovo.data.g, &nuovo.data.m, &nuovo.data.a);
    //Per ipotesi si suppone che la matricola sia sicuramente all'interno 
    //del vettore degli studenti
    for (int i = 0; i < c->numero_studenti; i++) {
        if (strncmp(matricola, c->studenti[i].matricola, LEN_STRINGHE) == 0) {
            int numero_esame = c->studenti[i].numero_esami;
            c->studenti[i].esami[numero_esame] = nuovo;
            c->studenti[i].numero_esami++;
            return;
        }
    }
}

int studente_passato_esame(Studente s, char esame[]) {
    for (int i = 0; i < s.numero_esami; i++) {
        if (strncmp(esame, s.esami[i].materia, LEN_STRINGHE) == 0) {
            return 1;
        }
    }
    return 0;
}

void stampa_passati(CorsoDiStudi c, char esame[]) {
    for (int i = 0; i < c.numero_studenti; i++) {
        if (studente_passato_esame(c.studenti[i], esame))
            stampa_studente(c.studenti[i]);
    }
}

float media_studente(Studente s){
    if (s.numero_esami != 0) {
        float somma = 0;
        for (int i = 0; i < s.numero_esami; i++) {
            somma +=s.esami[i].voto;
        }
        return somma/s.numero_esami;
    }
    return -1;
}

void stampa_media_studente(CorsoDiStudi corso, char matricola[]){
    
}

int main() {
    CorsoDiStudi corso;
    //Indico che inizialmente non ci sono studenti
    corso.numero_studenti = 0;
    //corso.nome = "Medicina"; //NO
    strncpy(corso.nome, "Medicina", LEN_STRINGHE);
    int scelta;
    menu();
    printf("Scegli l'operazione da svolgere: ");
    scanf("%d", &scelta);
    while (scelta != 0) {
        switch (scelta) {
            //Aggiunta di un nuovo studente
            case 1:
                {
                    Studente nuovo;
                    printf("Inserisci il nome dello studente: ");
                    scanf("%s", nuovo.nome);
                    printf("Inserisci il cognome: ");
                    scanf("%s", nuovo.cognome);
                    printf("Inserisci la matricola: ");
                    scanf("%s", nuovo.matricola);
                    nuovo.numero_esami = 0;
                    aggiungi_studente(&corso, nuovo);
                }
                break;
            //Aggiunta di un nuovo esame
            case 2:
                {
                    char matricola[LEN_STRINGHE];
                    printf("Inserisci il numero di matricola: ");
                    scanf("%s", matricola);
                    aggiungi_esame(&corso, matricola);
                }
                break;
            //Stampa le persone passate ad un esame
            case 3:
                {
                    char esame[LEN_STRINGHE];
                    printf("Inserisci il nome dell'esame: ");
                    scanf("%s", esame);
                    stampa_passati(corso, esame);
                }
            case 4:
                {
                    //Input della matricola
                    char esame[LEN_STRINGHE];
                    char matricola[LEN_STRINGHE];
                    printf("Inserisci il nome della matricola");
                    scanf("%s", matricola);
                    printf("Inserisci il nome dell'esame: ");
                    scanf("%s", esame);
                    stampa_media_studente(corso, matricola);
                }
                break;
            //Errore
            default:
                printf("Scelta non valida\n");
        }
        stampa_corso(corso);
        menu();
        printf("Scegli l'operazione da svolgere: ");
        scanf("%d", &scelta);
    }

    return 0;
}

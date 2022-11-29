#include <stdio.h>
#include <string.h>

#define N   3

int arrotonda(float *n) {
    float *p;
    p = n;
    do {
        *p *= 10;
        if (((int)*p % 10) < 5)
            return (int) *p / 10;
        if (((int) *p % 10) > 5)
            return ((int) *p + 10) / 10;
    } while (((int) *p % 10) == 5);
}

int inserisci_voto(char *cognomi[N], int *voti[10], int n, char *cognome, int voto){
    int i;
    for (i = 0; i < n && !strncmp(cognomi[i], cognome, n); i++)
        ;
    if (strncmp(cognomi[i], cognome, n)) {
        int j;
        for (j = 0; j < 10 && voti[i][j] != 0; j++)
            ;
        if (voti[j] != 0) 
            return -2;
        voti[i][j] = voto;
        return 1;
    }
    return -1;
}

void stampa_proposte(char *cognomi[N], int *voti[10], int n){
    for (int i = 0; i < n; i++) {
        printf("Studente %s: voti presenti: ", cognomi[i]);
        int j;
        for (j = 0; j < 10 && voti[i][j] != 0; j++)
            ;
        printf("%d media: ", j);
        float somma;
        for (int k = 0; k < j; k++) {
            somma += voti[i][k];
        }
        float media = somma / (j+1);
        printf("%g proposta: ", media);
        printf("%d", arrotonda(&media));
    }
}

int main() {
    int *voti[N];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < N; j++) {
            voti[i][j] = 0;
        }
    }
    
    char *studenti[N] = {"Bignotti", "Nusmani", "Verzelli"};

    inserisci_voto(studenti, voti, N, "Nusmani", 10);
    inserisci_voto(studenti, voti, N, "Nusmani", 2);
    inserisci_voto(studenti, voti, N, "Nusmani", 7);
    inserisci_voto(studenti, voti, N, "Nusmani", 7);
    inserisci_voto(studenti, voti, N, "Nusmani", 6);
    inserisci_voto(studenti, voti, N, "Bignotti", 3);
    inserisci_voto(studenti, voti, N, "Bignotti", 5);
    inserisci_voto(studenti, voti, N, "Varzelli", 1);
    inserisci_voto(studenti, voti, N, "Varzelli", 10);
    inserisci_voto(studenti, voti, N, "Varzelli", 6);
    stampa_proposte(studenti, voti, N);
    
    return 0;
}

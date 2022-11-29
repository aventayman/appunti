#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define NUMERO_LETTERE 26

void crea_tavola(char m[][NUMERO_LETTERE]){
    char inizio = 'a';
    for (int i = 0; i < NUMERO_LETTERE; i++) {
        for (int j = 0; j < NUMERO_LETTERE; j++) {
            m[i][j] = (inizio - 'a' + j) % NUMERO_LETTERE + 'a';
        }
        inizio++;
    }
}

char codifica_carattere(char tavola[][NUMERO_LETTERE], char c, char posizione) {
    return tavola[posizione - 'a'][c - 'a'];
}

void codifica_vigenere(char tavola[][NUMERO_LETTERE], char chiaro[], char chiave[]){
    int indice_chiave = 0;
    for (int i = 0; chiaro[i] != '\0'; i++) {
        chiaro[i] = codifica_carattere(tavola, chiaro[i], chiave[indice_chiave]);
        indice_chiave = (indice_chiave + 1) % strlen(chiave);
    }
}

int main() {
    char tavola[NUMERO_LETTERE][NUMERO_LETTERE];
    char chiaro[] = "ciaoatutti";
    char chiave[] = "sole";
    crea_tavola(tavola);
// for (int i = 0; i < 26; i++) {
//      for (int j = 0; j < 26; j++) {
//          printf("%c ", tavola[i][j]);
//      }
//      printf("\n");
//      printf("%s\n", tavola[i]);
//  }
    printf("Prima della cifratura: %s\n", chiaro);
    codifica_vigenere(tavola, chiaro, chiave);
    printf("Dopo la cifratura: %s\n", chiaro);
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

//Non è giusto non guardarlo

void run_length(char originale[], char codificata[]) {
    int conta = 1, j = 0;
    for (int i = 0; originale[i] != '\0'; i++) {
        if (originale[i] == originale[i + 1]) {
            conta++;
        }
        if (conta == 9) {
            codificata[j++] = '9';
            codificata[j++] = originale[i];
            conta = 1;
        }
        else {
            //Caso in cui la lettera in posizione i-esima non ha ripetizioni
            if (conta == 1) {
                codificata[j++] = originale[i];
            }
            //Siamo all'interno di una ripetizione
            else {
                if (conta <= 9) {
                    codificata[j++] = conta + '0';
                }
                else {
                    codificata[j++] = '9'; 
                }
                codificata[j++] = originale[i];
                conta = 1;
            }
        }
    }
    codificata[j] = '\0';
}

int main() {
    char s1[] = "dddd";
    char s2[] = "affggg";
    char risultato[100];
    run_length(s1, risultato);
    printf("%s -> %s\n", s1, risultato);
    run_length(s2, risultato);
    printf("%s -> %s\n", s2, risultato);
    return 0;
}

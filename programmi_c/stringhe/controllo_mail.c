#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int chiocciola(char mail[]) {
    int conta = 0;
    int pos;
    for (int i = 0; mail[i] != '\0'; i++) {
        if (mail[i] == '@') {
            conta++;
            pos = i;
        }         
    }    
    if (conta == 1) 
        return pos;
    return -1;
}

int lettera(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    return 0;
}

int punto(char s[]){
    int pos = 0, conta = 0;
    for (int i = 0; s[i] != 0; i++) {
        if (s[i] == '.') {
            pos = i;
            conta++;
        }
    }
    if (conta == 1)
        return pos;
    return -1;
}

int indirizzo_valido(char mail[]){
    //Regola 1
    int posizione_chiocciola;
    if ((posizione_chiocciola = chiocciola(mail)) == -1)
        return 0;
    
    //La prima parte non contiene niente
    //Regola 2
    if (posizione_chiocciola == 0)
        return -1;

    //Regola 3
    if (!lettera(mail[0]))
        return -1;
    if (punto(&mail[posizione_chiocciola]) == -1)
        return -1;
    int posizione_punto = punto(&mail[posizione_chiocciola]);
    //Se il punto è subito dopo la @ non va bene
    if (posizione_punto == 1)
        return -1;
    //Se il punto è in ultima posizione non va bene
    if (posizione_punto == strnlen(&mail[posizione_chiocciola], 100) - 1)
        return -1;
}

int main() {
    
    return 0;
}

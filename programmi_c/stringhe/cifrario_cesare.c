#include <stdio.h>

/*
 *
 * @param s Testo in chiaro
 * @param chiave Di quante posizioni in avanti devo modificare il carattere
 * */

char codifica_carattere(char s, int chiave){
    if (s > 'z' - chiave)
        s = s - 26;
    return s + chiave; 
}

char decodifica_carattere(char s, int chiave){
    if (s < 'a' + chiave)
        s = s + 26;
    return s - chiave;
}

void decodifica_cesare(char *s, int chiave){
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = decodifica_carattere(s[i], chiave);
    }
}

void codifica_cesare(char *s, int chiave){
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = codifica_carattere(s[i], chiave);
    }
}

int main() {
    char chiaro[] = "abcdefghijklmnopqrstuvwxyz";
    printf("%s\n", chiaro);
    codifica_cesare(chiaro, 3);
    printf("%s\n", chiaro);
    decodifica_cesare(chiaro, 3);
    printf("%s\n", chiaro);
    return 0;
}

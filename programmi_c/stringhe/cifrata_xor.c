#include <stdio.h>

void codifica_xor(char *s){
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = s[i] ^ 0xAA;
    }
}

void stampa_stringa(char *s){
    for (int i = 0; s[i] != '\0'; i++) {
        printf("%c -> %d\n", s[i], s[i]);
    }
}

int main() {
    char s[] = "Ciao mondo!";
    printf("%s\n", s);
    codifica_xor(s);
    printf("%s\n", s);
    stampa_stringa(s);
    codifica_xor(s);
    printf("%s\n", s);
    return 0;
}

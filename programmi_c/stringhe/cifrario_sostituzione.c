#include <stdio.h>

char codifica_carattere(char c, char *chiave){
    return chiave[c - 'a'];
}

char decodifica_carattere(char c, char *chiave){
    int i;
    for (i = 0; c != chiave[i]; i++)
        ;
    return i + 'a';
}

void codifica_sostituzione(char *s, char *chiave){
    for (int i = 0; s[i] != 0; i++) {
        s[i] = codifica_carattere(s[i], chiave);
    }
}

void decodifica_sostituzione(char *s, char *chiave){
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = decodifica_carattere(s[i], chiave);
    }
}

int main() {
    char chiave[] = "frkqwetyuiopasdghjlmnbvcxz";
    //Qui ci sarebbe da ripulire la stringa ma la mettiamo già giusta
    char chiaro[] = "attacchiamoaltramonto";
    codifica_sostituzione(chiaro, chiave);
    printf("%s\n", chiaro);
    decodifica_sostituzione(chiaro, chiave);
    printf("%s\n", chiaro);
    return 0;
}

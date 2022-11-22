#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void stampa_1(char s[])
{
    for (int i = 0; s[i] != '\0'; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}

void stampa_2(char s[])
{
    for (int i = 0; i < strlen(s); i++) {
        printf("%c", s[i]);
    }
    printf("\n");
}

void stampa_3(char *s)
{
    char *p = s;
    while(*p != '\0') {
        printf("%c", *p);
        p++;
    }
    printf("\n");
}

int main() {
    char s[] = "Ciao mondo buongiorno";
    stampa_3(s);
    return 0;
}

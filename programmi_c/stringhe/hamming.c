#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int hamming(char s1[], char s2[]){
    if (strlen(s1) != strlen(s2)) {
        return -1;
    }
    int contatore = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            contatore++;
        }
    }
    return contatore;
}
 
int main() {
    printf("%d", hamming("ciao", "mondo"));
    printf("%d", hamming("ciao", "ciao"));
    printf("%d", hamming("ciao", "ciai"));
    return 0;
}

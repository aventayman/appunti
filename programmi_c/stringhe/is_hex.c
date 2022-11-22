#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int carattere_corretto(char c) {
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')) {
        return 1;
    }
    return 0;
}

int is_hex(char s[]){
    if (s[0] != '0') {
        return 0;
    }

    if (s[1] != 'x' && s[1] != 'X') {
        return 0;
    }

    //Controllo se è troppo lunga
    if (strlen(s) > 10) {
        return 0;
    }

    for (int i = 2; s[i] != '\0'; i++) {
        //Normalmente si scriverebbe così
        //if (!carattere_corretto(s[i]))

        if (carattere_corretto(s[i]) != 1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("%d\n", is_hex("0x11"));
    printf("%d\n", is_hex("0i11"));
    printf("%d\n", is_hex("0iU1"));
    return 0;
}

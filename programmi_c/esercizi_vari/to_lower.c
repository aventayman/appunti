#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char isUpper(char c){
    if (c >= 'A' && c <= 'Z')
        return 1;
    else
        return 0;
}

int main() {
    char c;
    while ((c = getchar()) != EOF) {
        c = (isUpper(c)) ? c + 'a' - 'A': c;
        putchar(c);
    }
    return 0;
}

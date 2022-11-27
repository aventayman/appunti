/******************************************************************************
* File:             expand_string.c
*
* Author:           Ayman Marpicati  
* Created:          11/26/22 
* Description:      Si scriva una funzione expand(s1, s2) che espanda le
*                   notazioni stenografiche come a-z della stringa s1 nel
*                   corrispondente elenco completo abc...xyz in s2.
*                   Il programma deve affrontare casi come a-b-c, a-z0-9 e
*                   -a-z.
*****************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

void expand(char s1[], char s2[]){
    int c, n = 0, e = 0, j = 0;
    if (s1[n] == '-') {
        s2[n] = '-';
        n++;
        j++;
    }
    
    while (c != '\0') {
        c = s1[n];
        n = n + 2;
        e = s1[n];
        
        for (; c <= e; c++, j++) {
            s2[j] = c;
        }

        n++;
    }
    s2[j + 1] = '\n';
    s2[j + 2] = '\0';
}

int main() {
    char s1[] = "a-z0-9";
    char s2[MAX];

    expand(s1, s2);

    printf("%s", s2);
    return 0;
}

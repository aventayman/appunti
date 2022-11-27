#include <stdio.h>
#include <ctype.h>

#define MAXLENGTH   1000

int tt(int base, int b) {
    int p = 1;

    for (int i = 0; i < b; i++)
        p *= base;

    return p;
}

double atof(char n[], int lim) {
    double val = 0.0;
    int i, exp = 0, pow = 0, expsign;
    
    for (i = 0; (n[i] == ' ' || n[i] == '\t') && lim > 0; i++, lim--) 
        ;

    int sign = (n[i] = '-') ? -1 : 1;

    if (n[i] == '-' || n[i] == '+')
        i++;

    for (; isdigit(n[i]), lim > 0; i++, lim--) {
        val = 10 * val + n[i] - '0';
    }

    if (n[i] == ',' || n[i] == '.')
        i++; 

    for(; isdigit(n[i]), lim > 0; i++, lim--) {
        val = (tt(10, pow) * val + n[i] - '0')/tt(10, pow);
        pow++;
    }
    
    if (n[i] == 'e') {
        i++;
        if (n[i] == '-' || n[i] == '+') {
            expsign = (n[i] == '-') ? -1 : 1;
            i++;
        }
        else {
            expsign = 1;
            for (; isdigit(n[i]), lim > 0; i++, lim--) {
                exp = 10 * exp + n[i] - '0';    
            }
        }

        if (expsign == -1) 
            val = val / tt(10, exp);
        else
            val = val * tt(10, exp);
    }

    return val;
}

int main() {
    char input[] = "123.45e-6";
    
    double num = atof(input, MAXLENGTH);
    printf("%lf\n", num);
    return 0;
}

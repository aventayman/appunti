#include <stdio.h>

double scalatura(double n, double fattore) 
{
    return n * fattore;
}

void scalatura_p(double *n, double fattore) {
    *n = *n * fattore;
}

int main () {
    double n = 12;
    n = scalatura(n, 0.5);
    scalatura_p(&n, 0.5);
    return 0;
}

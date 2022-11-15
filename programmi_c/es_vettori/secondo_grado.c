#include <stdio.h>
#include <math.h>

double delta(double a, double b, double c) {
    return b*b - 4 * a * c;
}

void secondo_grado(double a, double b, double c, double *x1, double *x2) {
    *x1 = (+b + sqrt(delta(a, b, c)))/(2*a);
    *x2 = (+b - sqrt(delta(a, b, c)))/(2*a);
}

int main() {
    double a, b,c;
    double x1, x2;
    secondo_grado(a, b, c, &x1, &x2);
    printf("%lf %lf", x1, x2);
    return 0;
}

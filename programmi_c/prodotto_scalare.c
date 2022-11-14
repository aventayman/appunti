#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float prodotto_scalare(float v1[], float v2[], int n)
{
    float prodotto = 0;
    for (int i = 0; i < n; ++i) {
        prodotto += v1[i] * v2[i];
    }
    return prodotto;
}
    
int main() {
    float v1[] = {1.2, 12, 34.5};
    float v2[] = {3.4, 21.8, 12.1};
    printf("Il prodotto scalare è %f", prodotto_scalare(v1, v2, 3));
    
    return 0;
}

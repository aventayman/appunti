#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/******************************************************************************
* Function:         void rimuovi_elemento
* Description:      
* Where:
*                   int v[] - Il vettore da cui rimuovere un elemento
*                   int n - Il numero di elementi contenuti nel vettore
*                   int k - La posizione dell'elemento da rimuovere
* Return:           
* Error:            
*****************************************************************************/
void rimuovi_elemento(int v[], int n, int k){
    for (int i = k; i < n - 1; ++i) {
        v[i] = v[i + 1];
    }    
}

/******************************************************************************
* Function:         void rimuovi_elemento_fix
* Description:      
* Where:
*                   int v[] - Il vettore da cui rimuovere un elemento
*                   int n - Il numero di elementi contenuti nel vettore
*                   int k - La posizione dell'elemento da rimuovere
* Return:           
* Error:            
*****************************************************************************/
void rimuovi_elemento_fix(int v[], int *n, int k ){
    for (int i = 0; i < *n - 1; ++i) {
        v[i] = v [i + 1];
    }
    *n = *n - 1;
}

void rimuovi_elemento_copia(int v[], int c[], int n, int k)
{
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (i != k) {
            c[j] = v[i];
            j++;
        }
    } 
}
    
int main() {
    int v[] = {1,2,3,4,5,6,7};
    int c[10];
    rimuovi_elemento(v, 7, 3);
    for (int i = 0; i < 6; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
    int n = 5;
    rimuovi_elemento_fix(v, &n, 1);
    for (int i = 0; i < n; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
    rimuovi_elemento_copia(v, c, n, 0);
    n--;
    for (int i = 0; i < n; ++i) {
        printf("%d ", c[i]);
    }
    
    return 0;
}

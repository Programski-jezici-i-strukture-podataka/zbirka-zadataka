#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENATA 20

int main()
{
    int A[MAX_ELEMENATA];
    int n, i, brojParnih = 0, brojNeparnih = 0, i1, i2, brojNegativnih = 0;

    do
    {
        printf("Ucitati broj elemenata niza: ");
        scanf("%d", &n);
    } while((n < 2) || (n > MAX_ELEMENATA)); // n >= 2 && n <= MAX_ELEMENATA

    printf("\nUnesite elemente niza:\n\n");
    for(i = 0; i < n; i++)
    {
        printf("Unesite %d. element niza: ", i + 1);
        scanf("%d", &A[i]);
    }

    printf("\nElementi kojima je vrednost manja od njihovog indeksa u nizu: ");
    for(i = 0; i < n; i++)
    {
        if(A[i] < i)
            printf("%d ", A[i]);

        if(A[i] % 2 == 0)
            brojParnih++;
        else
            brojNeparnih++;
    }

    if(brojParnih > brojNeparnih)
        printf("\n\nVise ima parnih elemenata.\n");
    else if(brojNeparnih > brojParnih)
        printf("\n\nVise ima neparnih elemenata.\n");
    else
        printf("\n\nIma jednako parnih i neparnih elemenata.\n");

    printf("\nUnesite broj I1: ");
    scanf("%d", &i1);

    printf("Unesite broj I2: ");
    scanf("%d", &i2);

    for(i = i1; i <= i2; i++)
    {
        if(A[i] < 0)
            brojNegativnih++;
    }

    printf("\nBroj negativnih elemenata u intervalu od indeksa %d do %d je %d.\n", i1, i2, brojNegativnih);

    return 0;
}

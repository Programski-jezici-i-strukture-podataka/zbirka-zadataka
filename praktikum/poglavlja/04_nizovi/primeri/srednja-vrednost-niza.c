#include <stdio.h>

#define MAX_SIZE 30

int main()
{
    int i, n, niz[MAX_SIZE];

    do
    {
        printf("Unesite broj elemenata niza: ");
        scanf("%d", &n);
    } while(n <= 0 || n > MAX_SIZE);
    

    for(i = 0;i < n;i++)
    {
        printf("niz[%d]: ", i);
        scanf("%d", &niz[i]);
    }

    int suma = 0;
    for(i = 0;i < n;i++)
    {
        suma += niz[i];    // isto sto i "suma = suma + niz[i];"
    }

    printf("Srednja vrednost vrednosti iz niza je: %.2lf\n", (double)suma / n);

    return 0;
}

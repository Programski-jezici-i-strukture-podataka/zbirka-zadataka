#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENATA 20

int main()
{
    int A[MAX_ELEMENATA];
    int n, i, zbir = 0, maksimalni, minimalni;

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

    printf("\nElementi koji se nalaze na parnim pozicijama su: ");
    for(i = 0; i < n; i = i + 2)
    {
        printf("%d ", A[i]);
    }

    for(i = 0; i < n; i++)
    {
        if(A[i] > i)
            zbir = zbir + A[i];
    }

    printf("\n\nZbir elemenata koji su veci od svog indeksa je: %d\n\n", zbir);

    maksimalni = A[0];
    minimalni = A[0];

    for(i = 1; i < n; i++)
    {
        if(A[i] > maksimalni)
            maksimalni = A[i];
        else if(A[i] < minimalni)
            minimalni = A[i];
    }

    printf("Ostatak pri deljenju maksimalnog sa minimalnim elementom je: %d", maksimalni % minimalni);

    return 0;
}

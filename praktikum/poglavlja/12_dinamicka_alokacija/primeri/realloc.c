#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a, n;

    do
    {
        printf("Unesite duzinu niza: ");
        scanf("%d", &n);

    } while(n <= 0);

    a = (int *) malloc(n * sizeof(int));

    if (a == NULL)
    {
        printf("Memorija se ne moze zauzeti.\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    int m;

    do
    {
        printf("Unesite novu duzinu niza: ");
        scanf("%d", &m);

    } while(m <= 0);

    // Pokušaj da se poveća veličina niza koristeći realloc
    int *tmp = (int *) realloc(a, m * sizeof(int));

    // Provera da li realloc nije uspeo
    if (tmp == NULL)
    {
        // Greška pri alokaciji, originalni blok je i dalje validan
        free(a); // Oslobađanje prethodno alocirane memorije
        printf("Memorija se ne moze zauzeti.\n");
        exit(EXIT_FAILURE);
    }

    // Ako realloc uspe, dodeljujemo novi pokazivač
    a = tmp;

    if (m > n)
    {
        for(int i = n; i < m; i++)
        {
            printf("a[%d] = ", i);
            scanf("%d", &a[i]);
        }
    }

    printf("Uneti niz je:\n");
    for(int i = 0; i < m; i++)
    {
        printf("a[%d] = %d\n", i, a[i]);
    }

    free(a);
    return 0;
}

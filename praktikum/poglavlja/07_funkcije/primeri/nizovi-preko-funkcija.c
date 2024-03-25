#include <stdio.h>
#define MAX_SIZE 30

void dodavanje(int *a, int *pn);
int suma(int *a, int n);
void ispis(int *a, int n);

int main()
{
    int a[MAX_SIZE], n;
    
    dodavanje(a, &n);
    ispis(a, n);
    printf("Suma svih clanova niza je: %d\n", suma(a, n));
    
    return 0;
}

void dodavanje(int *a, int *n)
{
    int i;

    do
    {
        printf("Unesite broj clanova niza: ");
        scanf("%d", n);
    } while(*n <= 0 || *n > MAX_SIZE);

    for (i = 0; i < *n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

int suma(int *a, int n)
{
    int i, s = 0;

    for(i = 0;i < n;i++)
    {
        s += a[i];
    }

    return s;
}

void ispis(int *a, int n)
{
    int i;

    printf("[");
    for (i = 0; i < n; i++)
    {
        if (i > 0)
        {
            printf(", ");
        }
        printf("%d", a[i]);
    }
    printf("]\n");
}
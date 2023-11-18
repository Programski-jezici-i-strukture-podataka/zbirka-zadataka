#include <stdio.h>

#define MAX_SIZE 30

int main()
{
    int niz[MAX_SIZE], i, n;

    do
    {
        printf("Unesite velicinu niza: ");
        scanf("%d", &n);
    } while (n <= 0 || n > MAX_SIZE);
    
    for(i = 0;i < n;i++)
    {
        printf("niz[%d]: ", i);
        scanf("%d", &niz[i]);
    }

    int tekuci = 1, sledeci = 1, tmp;

    while(tekuci < niz[0])
    {
        tmp = tekuci;
        tekuci = sledeci;
        sledeci += tmp;
    }

    int je_fibonacijev = 1;

    if(tekuci > niz[0])
    {
        je_fibonacijev = 0;
    }
    else
    {
        if(n >= 2 && niz[1] != sledeci)
        {
            je_fibonacijev = 0;
        }
        else
        {
            for(i = 0;i < n - 2;i++)
            {
                if(niz[i + 2] != niz[i] + niz[i + 1])
                {
                    je_fibonacijev = 0;
                    break;
                }
            }
        }
    }

    if(je_fibonacijev)
    {
        printf("\nZadati niz je podskup Fibonacijevog niza: ");
        for(i = 0;i < n;i++)
        {
            if(i > 0)
            {
                printf(", ");
            }
            printf("%d", niz[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nZadati niz nije podskup Fibonacijevog niza!\n");
    }

    return 0;
}

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

    int nema_promena, j, tmp;

    for(i = 0;i < n - 1;i++)
    {
        nema_promena = 1;   // pretpostavimo da nece biti promena
        for(j = 0;j < n - i - 1;j++)
        {
            if(niz[j] > niz[j + 1])
            {
                tmp = niz[j];
                niz[j] = niz[j + 1];
                niz[j + 1] = tmp;
                nema_promena = 0;   // desila se promena, nema_promena postaje netacno
            }
        }

        if(nema_promena)
        {
            break;
        }
    }

    for(i = 0;i < n;i++)
    {
        printf("%d ", niz[i]);
    }

    return 0;
}

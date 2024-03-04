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

    int indeks_najmanjeg, j, tmp;

    for(i = 0;i < n - 1;i++)
    {
        indeks_najmanjeg = i;

        for(j = i + 1;j < n;j++)
        {
            if(niz[indeks_najmanjeg] > niz[j])
            {
                indeks_najmanjeg = j;
            }
        }

        if(indeks_najmanjeg != i)
        {
            tmp = niz[i];
            niz[i] = niz[indeks_najmanjeg];
            niz[indeks_najmanjeg] = tmp;
        }
    }

    for(i = 0;i < n;i++)
    {
        printf("%d ", niz[i]);
    }

    return 0;
}

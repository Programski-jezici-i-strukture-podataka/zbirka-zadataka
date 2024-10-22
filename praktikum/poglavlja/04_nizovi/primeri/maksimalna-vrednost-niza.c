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

    int maks = niz[0];

    for(i = 1;i < n;i++)
    {
        if(niz[i] > maks)
        {
            maks = niz[i];
        }
    }

    printf("Maksimalna vrednost niza je: %d\n", maks);

    return 0;
}

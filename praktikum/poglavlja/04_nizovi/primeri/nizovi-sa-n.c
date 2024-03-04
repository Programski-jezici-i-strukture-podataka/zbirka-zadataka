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

    for(i = 0;i < n;i++)
    {
        printf("%d ", niz[i]);
    }

    return 0;
}

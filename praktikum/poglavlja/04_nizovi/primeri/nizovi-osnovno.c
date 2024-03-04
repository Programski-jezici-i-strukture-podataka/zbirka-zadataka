#include <stdio.h>

int main()
{
    int i, niz[5];

    for(i = 0;i < 5;i++)
    {
        printf("niz[%d]: ", i);
        scanf("%d", &niz[i]);
    }

    for(i = 0;i < 5;i++)
    {
        printf("%d ", niz[i]);
    }

    return 0;
}

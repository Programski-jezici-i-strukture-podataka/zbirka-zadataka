#include <stdio.h>

#define MAX_SIZE 10

int main()
{
    int niz[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *pniz;

    pniz = niz;

    while(pniz - niz < MAX_SIZE)
    {
        printf("%d ", *pniz);
        pniz += 2;
    }

    return 0;
}

#include <stdio.h>

#define MAX_SIZE 10

int main()
{
    int i, niz[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(i = 0;i < MAX_SIZE;i += 2)
    {
        printf("%d ", niz[i]);
    }

    return 0;
}

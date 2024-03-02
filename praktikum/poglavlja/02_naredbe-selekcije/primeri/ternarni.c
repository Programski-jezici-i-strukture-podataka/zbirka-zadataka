#include <stdio.h>

int main()
{
    int x = 3, y = 5, veci;

    veci = x > y ? x : y;

    printf("Veci je %d\n", veci);

    return 0;
}
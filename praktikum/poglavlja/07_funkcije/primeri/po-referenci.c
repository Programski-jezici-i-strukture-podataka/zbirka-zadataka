#include <stdio.h>

void fun(int *pi);

int main()
{
    int i = 5;

    fun(&i);
    printf("Vrednost i: %d\n", i);

    return 0;
}

void fun(int *pi)
{
    *pi = 3;
}

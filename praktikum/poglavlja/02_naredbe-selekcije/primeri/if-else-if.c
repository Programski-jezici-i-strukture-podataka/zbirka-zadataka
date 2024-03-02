#include <stdio.h>

int main()
{
    int x = 6, y = 6;

    if(x > y)
        printf("X je vece\n");
    else if(x == y)
        printf("Jednaki su\n");
    else
        printf("Y je vece\n");

    return 0;
}
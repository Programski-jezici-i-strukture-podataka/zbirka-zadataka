#include <stdio.h>

int main()
{
    int b, a = 2024;

    printf("Pogodi broj!\n");
    do 
    {
        scanf("%d",&b);
        if (a > b) 
        {
            printf("Pokusaj ponovo, trazeni broj je veci od unetog!\n");
        } 
        else if (a < b)
        {
            printf("Pokusaj ponovo, trazeni broj je manji od unetog!\n");
        }
    } while(a != b);

    printf("Cestitam! Trazeni broj je %d.\n", a);
    return 0;
}

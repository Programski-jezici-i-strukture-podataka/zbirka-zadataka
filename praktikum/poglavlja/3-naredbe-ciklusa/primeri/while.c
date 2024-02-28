#include <stdio.h>

int main()
{
    int b, a = 2024;

    printf("Pogodi broj!\n");
    scanf("%d",&b);

    while(a != b) {
        printf("Pokusaj ponovo, trazeni broj je ");
        if(a < b) {
            printf("manji");
        } else {
            printf("veci");
        }
        printf(" od unetog!\n");
        scanf("%d",&b);
    }
    printf("Cestitam! Trazeni broj je %d.\n", a);

    return 0;
}

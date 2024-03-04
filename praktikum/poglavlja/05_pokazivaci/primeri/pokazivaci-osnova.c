#include <stdio.h>

int main()
{
    int broj = 5;
    int *pbroj;

    pbroj = &broj;

    printf("Vrednost broja posredstvom pokazivaca: %d\n", *pbroj);
    *pbroj = 6;
    printf("Vrednost broja: %d\n", broj);

    return 0;
}

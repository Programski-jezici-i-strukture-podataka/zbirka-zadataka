#include <stdio.h>

int zbir(int a, int b)
{
    int c;
    c = a + b;

    return c;
}

int main()
{
    int prvi_broj, drugi_broj;

    printf("Unesite prvi broj: ");
    scanf("%d", &prvi_broj);

    printf("Unesite drugi broj: ");
    scanf("%d", &drugi_broj);

    int rezultat = zbir(prvi_broj, drugi_broj);
    printf("Rezultat sabiranja: %d\n", rezultat);

    return 0;
}

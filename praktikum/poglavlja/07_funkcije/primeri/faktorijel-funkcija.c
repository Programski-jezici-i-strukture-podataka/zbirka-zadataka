#include <stdio.h>

#define FAKTORIJEL_GRESKA -1

int faktorijel(int broj);

int main()
{
    printf("Faktorijel od 0: %d\n", faktorijel(0));

    if(faktorijel(-5) == FAKTORIJEL_GRESKA)
    {
        printf("Nije moguce dobiti faktorijel od negativnog broja!\n");
    }

    printf("Faktorijel od 5: %d\n", faktorijel(5));

    return 0;
}

int faktorijel(int broj)
{
    int i, fakt = 1;

    if(broj < 0)
    {
        return FAKTORIJEL_GRESKA;
    }
    else if(broj == 0)
    {
        return 1;
    }

    for(i = 2;i <= broj;i++)
    {
        fakt *= i;
    }

    return fakt;
}

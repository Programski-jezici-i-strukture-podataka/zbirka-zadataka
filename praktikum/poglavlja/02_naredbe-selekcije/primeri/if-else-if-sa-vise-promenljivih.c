#include <stdio.h>

int main()
{
    int godine, plata;

    printf("Unesite godine: ");
    scanf("%d", &godine);
    printf("Unesite platu: ");
    scanf("%d", &plata);

    if(godine <= 20 || plata <= 70000)
    {
        printf("Moguce je podici kredit do 100000\n");
    }
    else if(godine <= 50 || plata <= 120000)
    {
        printf("Moguce je podici kredit do 180000\n");
    }
    else if(godine > 50)
    {
        printf("Ne moze se podici kredit zbog starosne granice\n");
    }

    return 0;
}
#include <stdio.h>

#define MAX_MARKA 51
#define MAX_MODEL 51

struct automobil
{
    char marka[MAX_MARKA];
    char model[MAX_MODEL];
    int kubikaza;
    int godiste;
    float cena;
};

int main()
{

    struct automobil a;

    printf("Unesite marku: ");
    scanf("%s", a.marka);
    printf("Unesite model: ");
    scanf("%s", a.model);
    printf("Unesite kubikazu: ");
    scanf("%d", &a.kubikaza);
    printf("Unesite godiste: ");
    scanf("%d", &a.godiste);
    printf("Unesite cenu: ");
    scanf("%f", &a.cena);

    printf("\nModel autmobila %s marke %s sa kubikazom %d proizveden %d. godine je cene %.2f\n", a.model, a.marka, a.kubikaza, a.godiste, a.cena);

    return 0;
}

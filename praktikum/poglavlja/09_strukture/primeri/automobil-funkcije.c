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

void unos_automobila(struct automobil *);
void ispis_automobila(struct automobil);

int main()
{

    struct automobil a1;
    struct automobil a2;
    unos_automobila(&a1);
    printf("\n");
    unos_automobila(&a2);

    ispis_automobila(a1);
    ispis_automobila(a2);

    return 0;
}


void unos_automobila(struct automobil *a)
{
    printf("Unesite marku: ");
    scanf("%s", a->marka);
    printf("Unesite model: ");
    scanf("%s", (*a).model);
    printf("Unesite kubikazu: ");
    scanf("%d", &(a->kubikaza));
    printf("Unesite godiste: ");
    scanf("%d", &((*a).godiste));
    printf("Unesite cenu: ");
    scanf("%f", &(a->cena));
}

void ispis_automobila(struct automobil a)
{
    printf("\nModel autmobila %s marke %s sa kubikazom %d proizveden %d. godine je cene %.2f\n", a.model, a.marka, a.kubikaza, a.godiste, a.cena);
}

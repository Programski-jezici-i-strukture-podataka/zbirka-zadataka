#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAZIV_LINIJE 51
#define MAX_VREME_DOLASKA 5

#define MAX_SIZE 30

typedef struct linija_st
{
    char naziv_linije[MAX_NAZIV_LINIJE];
    int broj_linije;
    char vreme_dolaska[MAX_VREME_DOLASKA];
} LINIJA;

void ucitaj_linije(LINIJA *, int *);
void ispis_trazene_linije(LINIJA *, int, char *, int);

int main(int argc, char **argv)
{
    LINIJA linije[MAX_SIZE];
    int n;

    if(argc != 2)
    {
        printf("Primer poziva: %s 1800\n", argv[0]);
        exit(2);
    }

    ucitaj_linije(linije, &n);

    int trazena_linija;

    // Zarad jednostavnosti, prilikom unosa, pretpostaviti da se jedna linija ne moze izabrati vise puta
    printf("Uneti brojeve od 1 do 15 ili -1 za izlazak:\n");
    do
    {
        printf("Linija: ");
        scanf("%d", &trazena_linija);
        if(trazena_linija < -1 || trazena_linija == 0 || trazena_linija > 15)
        {
            printf("Ne postoji zadata linija!\n");
        }
        else if(trazena_linija != -1)
        {
            ispis_trazene_linije(linije, n, argv[1], trazena_linija);
        }
    } while(trazena_linija != -1);

    return 0;
}

void ucitaj_linije(LINIJA *linije, int *pn)
{
    int i;

    do
    {
        scanf("%d", pn);
    } while (*pn <= 0 || *pn > MAX_SIZE);

    for (i = 0;i < *pn;i++)
    {
        scanf("%s %d %s", linije[i].naziv_linije, &linije[i].broj_linije, linije[i].vreme_dolaska);
    }
}

void ispis_trazene_linije(LINIJA *linije, int n, char *vreme, int trazena_linija)
{
    int i, nadjena_linija;

    for(i = 0;i < n;i++)
    {
        if(linije[i].broj_linije == trazena_linija && strcmp(vreme, linije[i].vreme_dolaska) < 0)
        {
            printf("%d %s\n", linije[i].broj_linije, linije[i].vreme_dolaska);
        }
    }
}

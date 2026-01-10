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

FILE *safe_fopen(char *, char *, int);
void ucitaj_linije(FILE *, LINIJA *, int *);
void ispis_trazene_linije(FILE *, LINIJA *, int, char *, int);

int main(int argc, char **argv)
{
    LINIJA linije[MAX_SIZE];
    int n;

    if(argc != 4)
    {
        printf("Primer poziva: %s linije.txt trazene-linije.txt 1800\n", argv[0]);
        exit(2);
    }

    FILE *ulazna = safe_fopen(argv[1], "r", 3);
    ucitaj_linije(ulazna, linije, &n);
    fclose(ulazna);

    int trazena_linija;
    FILE *izlazna = safe_fopen(argv[2], "w", 4);

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
            ispis_trazene_linije(izlazna, linije, n, argv[3], trazena_linija);
        }
    } while(trazena_linija != -1);

    fclose(izlazna);

    return 0;
}

FILE *safe_fopen(char *naziv, char *rezim, int kod_greske)
{
    FILE *fp = fopen(naziv, rezim);

    if(fp == NULL)
    {
        printf("Datoteka %s nije uspesno otvorena!\n", naziv);
        exit(kod_greske);
    }

    return fp;
}

void ucitaj_linije(FILE *ulazna, LINIJA *linije, int *pn)
{
    int i = 0;

    while(fscanf(ulazna, "%s %d %s", 
            linije[i].naziv_linije, &linije[i].broj_linije, linije[i].vreme_dolaska) != EOF)
    {
        i++;
    }

    *pn = i;
}

void ispis_trazene_linije(FILE *izlazna, LINIJA *linije, int n, char *vreme, int trazena_linija)
{
    int i, nadjena_linija;

    for(i = 0;i < n;i++)
    {
        if(linije[i].broj_linije == trazena_linija && strcmp(vreme, linije[i].vreme_dolaska) < 0)
        {
            fprintf(izlazna, "%d %s\n", linije[i].broj_linije, linije[i].vreme_dolaska);
        }
    }
}

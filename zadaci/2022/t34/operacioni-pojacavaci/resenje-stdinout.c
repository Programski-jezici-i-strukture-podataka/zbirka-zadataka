#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_NAZIV 11

#define MAX_POJACAVACA 20

typedef struct pojacavac_st {
    char naziv[MAX_NAZIV];
    int pojacanje;
    int napajanje;
    int ofset;
} POJACAVAC;

void ucitaj_pojacavace(POJACAVAC *, int *);
void ispisi_pojacavace(POJACAVAC *, int, double, double);
void ispisi_auto_zero(POJACAVAC *, int, double, double);
POJACAVAC pronadji_naj_pojacavac(POJACAVAC *, int);

int main(int argc, char **argv) {
    POJACAVAC pojacavaci[MAX_POJACAVACA];
    int n;

    if(argc != 3) {
        printf("Primer poziva programa: %s 139.7 117.9\n", argv[0]);
        exit(1);
    }

    ucitaj_pojacavace(pojacavaci, &n);

    double ul1 = atof(argv[1]) / 1000;
    double ul2 = atof(argv[2]) / 1000;

    printf("\n");
    ispisi_pojacavace(pojacavaci, n, ul1, ul2);
    ispisi_auto_zero(pojacavaci, n, ul1, ul2);

    POJACAVAC naj_pojacavac = pronadji_naj_pojacavac(pojacavaci, n);
    printf("\nNajvece pojacanje ima: %s, i ono iznosi: %d\n", naj_pojacavac.naziv, naj_pojacavac.pojacanje);

    return 0;
}

void ucitaj_pojacavace(POJACAVAC *pojacavaci, int *pn) {
    int i;

    do
    {
        printf("Unesite broj operacionih pojacavaca: ");
        scanf("%d", pn);
    } while (*pn <= 0 || *pn > MAX_POJACAVACA);
    

    for(i = 0;i < *pn;i++)
    {
        printf("Operacioni pojacavac: ");
        scanf("%s %d %d %d",
            pojacavaci[i].naziv,
            &pojacavaci[i].pojacanje,
            &pojacavaci[i].napajanje,
            &pojacavaci[i].ofset);
    }
}

void ispisi_pojacavace(POJACAVAC *pojacavaci, int n, double ul1, double ul2)
{
    int i;

    for(i = 0; i < n; i++)
    {
        double izlaz = (double)pojacavaci[i].pojacanje * fabs(ul1 - ul2);
        if((pojacavaci[i].napajanje > izlaz) && (pojacavaci[i].ofset != 0))
        {
            double procenat = (1 - (pojacavaci[i].napajanje - (double)pojacavaci[i].ofset)/(2 * pojacavaci[i].napajanje)) * 100;
            printf("%s %.2lf %.2lf%%\n", pojacavaci[i].naziv, izlaz, procenat);
        }
    }

    printf("-------------------------\n");
}

void ispisi_auto_zero(POJACAVAC *pojacavaci, int n, double ul1, double ul2)
{
    int i;

    for(i = 0; i < n; i++)
    {
        double izlaz = (double)pojacavaci[i].pojacanje * fabs(ul1 - ul2);
        if((pojacavaci[i].napajanje > izlaz) && (pojacavaci[i].ofset == 0))
        {
            printf("%s %.2lf %s\n", pojacavaci[i].naziv, izlaz, "AZ");
        }
    }
}

POJACAVAC pronadji_naj_pojacavac(POJACAVAC *pojacavaci, int n)
{
    POJACAVAC max = pojacavaci[0];
    int i;

    for(i = 1; i < n; i++)
    {
        if (pojacavaci[i].pojacanje > max.pojacanje)
        {
            max = pojacavaci[i];
        }
    }

    return max;
}

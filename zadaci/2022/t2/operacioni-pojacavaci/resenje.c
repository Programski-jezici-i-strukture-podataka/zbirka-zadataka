#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_NAZIV 11

#define MAX_POJACAVACA 20

#define MAX_IME_DATOTEKE 30

typedef struct pojacavac_st {
    char naziv[MAX_NAZIV];
    int pojacanje;
    int napajanje;
    int ofset;
} POJACAVAC;

FILE *safe_fopen(char *, char *, int);
void ucitaj_pojacavace(FILE *, POJACAVAC *, int *);
void ispisi_pojacavace(FILE *, POJACAVAC *, int, double, double);
void ispisi_auto_zero(FILE *, POJACAVAC *, int, double, double);
POJACAVAC pronadji_naj_pojacavac(POJACAVAC *, int);

int main(int argc, char **argv) {
    POJACAVAC pojacavaci[MAX_POJACAVACA];
    int n;

    if(argc != 4) {
        printf("Primer poziva programa: %s opamps.txt 139.7 117.9\n", argv[0]);
        exit(1);
    }

    FILE *pulazna = safe_fopen(argv[1], "r", 2);
    ucitaj_pojacavace(pulazna, pojacavaci, &n);
    fclose(pulazna);

    double ul1 = atof(argv[2]) / 1000;
    double ul2 = atof(argv[3]) / 1000;
    
    char ime_datoteke[MAX_IME_DATOTEKE] = "operacioni_pojacavaci.txt";
    FILE *pizlazna = safe_fopen(ime_datoteke, "w", 3);
    ispisi_pojacavace(pizlazna, pojacavaci, n, ul1, ul2);
    ispisi_auto_zero(pizlazna, pojacavaci, n, ul1, ul2);

    POJACAVAC naj_pojacavac = pronadji_naj_pojacavac(pojacavaci, n);
    printf("Najvece pojacanje ima: %s, i ono iznosi: %d\n", naj_pojacavac.naziv, naj_pojacavac.pojacanje);
    fclose(pizlazna);

    return 0;
}

FILE *safe_fopen(char *ime, char *rezim, int kod_greske) {
    FILE *fp = fopen(ime, rezim);

    if(fp == NULL) {
        printf("Greska prilikom otvaranja %s datoteke!\n", ime);
        exit(kod_greske);
    }

    return fp;
}

void ucitaj_pojacavace(FILE *pulazna, POJACAVAC *pojacavaci, int *pn) {
    int i = 0;

    while(fscanf(pulazna, "%s %d %d %d",
                 pojacavaci[i].naziv,
                 &pojacavaci[i].pojacanje,
                 &pojacavaci[i].napajanje,
                 &pojacavaci[i].ofset) != EOF) {
        i++;
    }

    *pn = i;
}

void ispisi_pojacavace(FILE *pizlazna, POJACAVAC *pojacavaci, int n, double ul1, double ul2)
{
    int i;

    for(i = 0; i < n; i++)
    {
        double izlaz = (double)pojacavaci[i].pojacanje * fabs(ul1 - ul2);
        if((pojacavaci[i].napajanje > izlaz) && (pojacavaci[i].ofset != 0))
        {
            double procenat = (1 - (pojacavaci[i].napajanje - (double)pojacavaci[i].ofset)/(2 * pojacavaci[i].napajanje)) * 100;
            fprintf(pizlazna, "%s %.2lf %.2lf%%\n", pojacavaci[i].naziv, izlaz, procenat);
        }
    }

    fprintf(pizlazna, "-------------------------\n");
}

void ispisi_auto_zero(FILE *pizlazna, POJACAVAC *pojacavaci, int n, double ul1, double ul2)
{
    int i;

    for(i = 0; i < n; i++)
    {
        double izlaz = (double)pojacavaci[i].pojacanje * fabs(ul1 - ul2);
        if((pojacavaci[i].napajanje > izlaz) && (pojacavaci[i].ofset == 0))
        {
            fprintf(pizlazna, "%s %.2lf %s\n", pojacavaci[i].naziv, izlaz, "AZ");
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

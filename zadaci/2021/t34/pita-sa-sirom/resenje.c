#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NIZ 30

#define MAX_SIROVINA 31

typedef struct sirovine_st {
    char naziv_sirovine[MAX_SIROVINA];
    unsigned limit_za_velikoprodaju;
    double maloprodajna_cena;
    double velikoprodajna_cena;
} SIROVINE;

FILE *safe_fopen(char *naziv, char *rezim, int kod_greske);
void ucitaj_sirovine(FILE *pulazna, SIROVINE *sirovine, int *pn);
void ispisi_cene(FILE *pizlazna, SIROVINE *sirovine, int n, unsigned kolicina);
double izracunaj_kolicinu_sirovine(char *naziv_sirovine, unsigned kolicina);
double izracunaj_cenu(double kolicina_sirovine, unsigned limit_za_velikoprodaju,
                      double maloprodajna_cena, double velikoprodajna_cena);

int main(int argc, char **argv) {
    SIROVINE sirovine[MAX_NIZ];
    int n;
    FILE *pulazna, *pizlazna;

    if(argc != 4) {
        printf("Primer poziva programa: %s sirovine.txt cene.txt 120\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pulazna = safe_fopen(argv[1], "r", 2);
    ucitaj_sirovine(pulazna, sirovine, &n);
    fclose(pulazna);

    pizlazna = safe_fopen(argv[2], "w", 3);
    unsigned kolicina = atoi(argv[3]);
    ispisi_cene(pizlazna, sirovine, n, kolicina);
    fclose(pizlazna);

    return EXIT_SUCCESS;
}

FILE *safe_fopen(char *naziv, char *rezim, int kod_greske) {
    FILE *fp = fopen(naziv, rezim);

    if(fp == NULL) {
        printf("Datoteka %s nije uspesno otvorena!\n", naziv);
        exit(kod_greske);
    }

    return fp;
}

void ucitaj_sirovine(FILE *pulazna, SIROVINE *sirovine, int *pn) {
    int i = 0;

    while(fscanf(pulazna, "%s %u %lf %lf",
                 sirovine[i].naziv_sirovine,
                 &sirovine[i].limit_za_velikoprodaju,
                 &sirovine[i].maloprodajna_cena,
                 &sirovine[i].velikoprodajna_cena) != EOF) {
        i++;
    }

    *pn = i;
}

void ispisi_cene(FILE *pizlazna, SIROVINE *sirovine, int n, unsigned kolicina) {
    int i;
    double kolicina_sirovine, cena_sirovine;

    for(i = 0;i < n;i++) {
        kolicina_sirovine = izracunaj_kolicinu_sirovine(
                                sirovine[i].naziv_sirovine,
                                kolicina
                            );
        cena_sirovine = izracunaj_cenu(
                            kolicina_sirovine,
                            sirovine[i].limit_za_velikoprodaju,
                            sirovine[i].maloprodajna_cena,
                            sirovine[i].velikoprodajna_cena
                        );
        fprintf(pizlazna, "%6s %5.2lf %8.2lf\n", sirovine[i].naziv_sirovine, kolicina_sirovine, cena_sirovine);
    }
}

double izracunaj_kolicinu_sirovine(char *naziv_sirovine, unsigned kolicina) {
    double udeo_sirovine;

    if(strcmp(naziv_sirovine, "brasno") == 0) {
        udeo_sirovine = 0.6;
    } else if(strcmp(naziv_sirovine, "sir") == 0) {
        udeo_sirovine = 0.4;
    } else if(strcmp(naziv_sirovine, "ulje") == 0) {
        udeo_sirovine = 0.1;
    } else if(strcmp(naziv_sirovine, "so") == 0) {
        udeo_sirovine = 0.02;
    } else {
        udeo_sirovine = 0;      // Nepoznata sirovina se nece ubrajati u proracun
    }

    return udeo_sirovine * kolicina;
}

double izracunaj_cenu(double kolicina_sirovine, unsigned limit_za_velikoprodaju,
                      double maloprodajna_cena, double velikoprodajna_cena) {

    double izabrana_cena = kolicina_sirovine < limit_za_velikoprodaju ? maloprodajna_cena : velikoprodajna_cena;
    return kolicina_sirovine * izabrana_cena;
}


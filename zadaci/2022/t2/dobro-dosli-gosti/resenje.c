#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAZIV 21

#define MAX_RESTORANA 20

#define MAX_IME_DATOTEKE 23

typedef struct restoran_st {
    char naziv[MAX_NAZIV];
    double cena_po_osobi;
    int kapacitet;
    int broj_konobara;
} RESTORAN;

FILE *safe_fopen(char *, char *, int);
void ucitaj_restorane(FILE *, RESTORAN *, int *);
double ukupna_cena_u_evrima(double, int, double);
int broj_gostiju_po_konobaru(int, int);
void ispisi_restorane(FILE *, RESTORAN *, int, int, double);
RESTORAN pronadji_optimalni_restoran(RESTORAN *, int, int);

int main(int argc, char **argv) {
    RESTORAN restorani[MAX_RESTORANA];
    int n;

    if(argc != 4) {
        printf("Primer poziva programa: %s restorani.txt 120 117.5\n", argv[0]);
        exit(1);
    }

    FILE *pulazna = safe_fopen(argv[1], "r", 2);
    ucitaj_restorane(pulazna, restorani, &n);
    fclose(pulazna);

    int broj_gostiju = atoi(argv[2]);
    double kurs_evra = atof(argv[3]);
    
    char ime_datoteke[MAX_IME_DATOTEKE] = "cene_za_";
    strcat(ime_datoteke, argv[2]);
    strcat(ime_datoteke, "_ljudi.txt");
    FILE *pizlazna = safe_fopen(ime_datoteke, "w", 3);
    ispisi_restorane(pizlazna, restorani, n, broj_gostiju, kurs_evra);
    RESTORAN optimalni_restoran = pronadji_optimalni_restoran(restorani, n, broj_gostiju);
    printf("Najpogodniji restoran za slavlje: %s %.2lfe 1/%d\n",
           optimalni_restoran.naziv,
           ukupna_cena_u_evrima(optimalni_restoran.cena_po_osobi, broj_gostiju, kurs_evra),
           (int)ceil((double)broj_gostiju / optimalni_restoran.broj_konobara));
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

void ucitaj_restorane(FILE *pulazna, RESTORAN *restorani, int *pn) {
    int i = 0;

    while(fscanf(pulazna, "%s %lf %d %d",
                 restorani[i].naziv,
                 &restorani[i].cena_po_osobi,
                 &restorani[i].kapacitet,
                 &restorani[i].broj_konobara) != EOF) {
        i++;
    }

    *pn = i;
}

double ukupna_cena_u_evrima(double cena_po_osobi, int broj_ljudi, double kurs) {
    return cena_po_osobi * broj_ljudi / kurs;
}

int broj_gostiju_po_konobaru(int broj_gostiju, int broj_konobara) {
    return (int)ceil((double)broj_gostiju / broj_konobara);
}

void ispisi_restorane(FILE *pizlazna, RESTORAN *restorani, int n, int broj_gostiju, double kurs) {
    int i;

    for(i = 0;i < n;i++) {
        if(restorani[i].kapacitet >= broj_gostiju) {
            fprintf(pizlazna, "%s %.2lfe 1/%d\n",
                    restorani[i].naziv,
                    ukupna_cena_u_evrima(restorani[i].cena_po_osobi, broj_gostiju, kurs),
                    broj_gostiju_po_konobaru(broj_gostiju, restorani[i].broj_konobara));
        } else {
            fprintf(pizlazna, "%s nedovoljno kapaciteta\n", restorani[i].naziv);
        }
    }
}

RESTORAN pronadji_optimalni_restoran(RESTORAN *restorani, int n, int broj_gostiju) {
    int i;
    RESTORAN optimalni_restoran;
    double min_koeficijent, koeficijent_restorana;

    for(i = 0;i < n;i++) {
        if(broj_gostiju <= restorani[i].kapacitet) {
            optimalni_restoran = restorani[i];
            min_koeficijent = restorani[i].cena_po_osobi / broj_gostiju_po_konobaru(broj_gostiju, restorani[i].broj_konobara);
            break;
        }
    }

    for(i = 0;i < n;i++) {
        if(broj_gostiju <= restorani[i].kapacitet) {
            koeficijent_restorana = restorani[i].cena_po_osobi / broj_gostiju_po_konobaru(broj_gostiju, restorani[i].broj_konobara);
            if(koeficijent_restorana < min_koeficijent) {
                optimalni_restoran = restorani[i];
                min_koeficijent = koeficijent_restorana;
            }
        }
    }

    return optimalni_restoran;
}


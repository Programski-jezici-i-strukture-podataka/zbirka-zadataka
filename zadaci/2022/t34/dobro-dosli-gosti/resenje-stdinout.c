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

void ucitaj_restorane(RESTORAN *, int *);
double ukupna_cena_u_evrima(double, int, double);
int broj_gostiju_po_konobaru(int, int);
void ispisi_restorane(RESTORAN *, int, int, double);
RESTORAN pronadji_optimalni_restoran(RESTORAN *, int, int);

int main(int argc, char **argv) {
    RESTORAN restorani[MAX_RESTORANA];
    int n;

    if(argc != 3) {
        printf("Primer poziva programa: %s 120 117.5\n", argv[0]);
        exit(1);
    }

    ucitaj_restorane(restorani, &n);

    int broj_gostiju = atoi(argv[1]);
    double kurs_evra = atof(argv[2]);

    ispisi_restorane(restorani, n, broj_gostiju, kurs_evra);
    RESTORAN optimalni_restoran = pronadji_optimalni_restoran(restorani, n, broj_gostiju);
    printf("Najpogodniji restoran za slavlje: %s %.2lfe 1/%d\n",
           optimalni_restoran.naziv,
           ukupna_cena_u_evrima(optimalni_restoran.cena_po_osobi, broj_gostiju, kurs_evra),
           (int)ceil((double)broj_gostiju / optimalni_restoran.broj_konobara));

    return 0;
}

void ucitaj_restorane(RESTORAN *restorani, int *pn) {
    int i;

    do
    {
        scanf("%d", pn);
    } while (*pn <= 0 || *pn > MAX_RESTORANA);

    for (i = 0;i < *pn;i++)
    {
        scanf("%s %lf %d %d",
            restorani[i].naziv,
            &restorani[i].cena_po_osobi,
            &restorani[i].kapacitet,
            &restorani[i].broj_konobara);
    }
}

double ukupna_cena_u_evrima(double cena_po_osobi, int broj_ljudi, double kurs) {
    return cena_po_osobi * broj_ljudi / kurs;
}

int broj_gostiju_po_konobaru(int broj_gostiju, int broj_konobara) {
    return (int)ceil((double)broj_gostiju / broj_konobara);
}

void ispisi_restorane(RESTORAN *restorani, int n, int broj_gostiju, double kurs) {
    int i;

    printf("Cene za %d ljudi: \n", broj_gostiju);

    for(i = 0;i < n;i++) {
        if(restorani[i].kapacitet >= broj_gostiju) {
            printf("%s %.2lfe 1/%d\n",
                restorani[i].naziv,
                ukupna_cena_u_evrima(restorani[i].cena_po_osobi, broj_gostiju, kurs),
                broj_gostiju_po_konobaru(broj_gostiju, restorani[i].broj_konobara));
        } else {
            printf("%s nedovoljno kapaciteta\n", restorani[i].naziv);
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


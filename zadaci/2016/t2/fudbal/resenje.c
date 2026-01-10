#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 30

#define MAX_NAZIV 31

#define MAX_IME_DATOTEKE 36

#define LIGA_SAMPIONA 3
#define LIGA_EVROPE 5
#define VELICINA_ZONE_ISPADANJA 3

typedef struct fudbal_st {
    char naziv_tima[MAX_NAZIV];
    int gol_razlika;
    unsigned broj_bodova;
} FUDBAL;

FILE *safe_fopen(char *naziv, char *rezim, int kod_greske);
void ucitaj_statistiku(FILE *pulazna, FUDBAL *ekipe, int *pn);
void ispisi_interval(FILE *pizlazna, FUDBAL *ekipe, int n, unsigned broj_bodova);
void ispisi_tabelu(FILE *pizlazna, FUDBAL *ekipe, int n);
unsigned suma_bodova(FUDBAL *ekipe, int n);
double prosek_bodova(FUDBAL *ekipe, int n);
void sortiraj_ekipe(FUDBAL *ekipe, int n);
unsigned izracunaj_bodove(unsigned broj_pobeda, unsigned broj_neresenih);

int main(int argc, char **argv) {
    FUDBAL ekipe[MAX_SIZE];
    int n;

    FILE *pulazna, *pizlazna_interval, *pizlazna_tabela;

    if(argc != 4) {
        printf("Primer poziva programa: %s statistika.txt tabela.txt 25\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // a

    pulazna = safe_fopen(argv[1], "r", 2);
    ucitaj_statistiku(pulazna, ekipe, &n);
    fclose(pulazna);

    // b
    
    char ime_datoteke[MAX_IME_DATOTEKE] = "izmedju_proseka_i_";
    strcat(ime_datoteke, argv[3]);
    strcat(ime_datoteke, "_bodova.txt");
    unsigned broj_bodova = atoi(argv[3]);
    pizlazna_interval = safe_fopen(ime_datoteke, "w", 3);
    ispisi_interval(pizlazna_interval, ekipe, n, broj_bodova);
    fclose(pizlazna_interval);

    // c

    sortiraj_ekipe(ekipe, n);
    pizlazna_tabela = safe_fopen(argv[2], "w", 4);
    ispisi_tabelu(pizlazna_tabela, ekipe, n);
    fclose(pizlazna_tabela);

    return EXIT_SUCCESS;
}

FILE *safe_fopen(char *naziv, char *rezim, int kod_greske) {
    FILE *fp = fopen(naziv, rezim);

    if(fp == NULL) {
        printf("Datoteku %s nije moguce otvoriti!\n", naziv);
        exit(kod_greske);
    }

    return fp;
}

void ucitaj_statistiku(FILE *pulazna, FUDBAL *ekipe, int *pn) {
    int i = 0;
    unsigned broj_pobeda, broj_neresenih, broj_poraza;

    while(fscanf(pulazna, "%s %d %u %u %u", 
                 ekipe[i].naziv_tima, 
                 &ekipe[i].gol_razlika,
                 &broj_pobeda,
                 &broj_neresenih,
                 &broj_poraza) != EOF) {
        // broj_poraza se ne koristi u daljim proracunima (ne dobijaju se bodovi), 
        // ali moramo ucitati iz datoteke kako bismo presli na ucitavanje novog reda
        ekipe[i].broj_bodova = izracunaj_bodove(broj_pobeda, broj_neresenih);
        i++;
    }

    *pn = i;
}

void ispisi_interval(FILE *pizlazna, FUDBAL *ekipe, int n, unsigned broj_bodova) {
    int i;

    double prosek = prosek_bodova(ekipe, n);

    for(i = 0;i < n;i++) {
        if(ekipe[i].broj_bodova >= prosek && ekipe[i].broj_bodova <= broj_bodova) {
            fprintf(pizlazna, "%s %d %u\n", ekipe[i].naziv_tima, ekipe[i].gol_razlika, ekipe[i].broj_bodova);
        }
    }
}

void ispisi_tabelu(FILE *pizlazna, FUDBAL *ekipe, int n) {
    int i;

    for(i = 0;i < n;i++) {
        if(i == LIGA_SAMPIONA || i == LIGA_EVROPE || i == n - VELICINA_ZONE_ISPADANJA) {
            fprintf(pizlazna, "-------------------\n");
        }
        fprintf(pizlazna, "%s %d %u\n", ekipe[i].naziv_tima, ekipe[i].gol_razlika, ekipe[i].broj_bodova);
    }
}

unsigned izracunaj_bodove(unsigned broj_pobeda, unsigned broj_neresenih) {
    return 3 * broj_pobeda + broj_neresenih;
}

unsigned suma_bodova(FUDBAL *ekipe, int n) {
    int i;    
    unsigned suma = 0;

    for(i = 0;i < n;i++) {
        suma += ekipe[i].broj_bodova;
    }

    return suma;
}

double prosek_bodova(FUDBAL *ekipe, int n) {
    return (double) suma_bodova(ekipe, n) / n;
}

void sortiraj_ekipe(FUDBAL *ekipe, int n) {
    int i, j, max_idx;
    FUDBAL tmp_ekipa;

    for(i = 0;i < n - 1;i++) {
        max_idx = i;
        for(j = i + 1;j < n;j++) {
            if(ekipe[max_idx].broj_bodova < ekipe[j].broj_bodova ||
               (ekipe[max_idx].broj_bodova == ekipe[j].broj_bodova && 
                ekipe[max_idx].gol_razlika < ekipe[j].gol_razlika)) {
                max_idx = j;
            }
        }

        if(i != max_idx) {
            tmp_ekipa = ekipe[i];
            ekipe[i] = ekipe[max_idx];
            ekipe[max_idx] = tmp_ekipa;
        }
    }
}


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAX_IME 21
#define MAX_PREZIME 31
#define MAX_POZICIJA 11

#define MAX_POSTAVA 6

#define MAX_FUDBALERA 20

typedef struct fudbaler_st {
    char ime[MAX_IME];
    char prezime[MAX_PREZIME];
    int broj_dresa;
    char pozicija[MAX_POZICIJA];
} FUDBALER;

FILE *safe_fopen(char *, char *, int);
void ucitaj_fudbalere(FILE *, FUDBALER *, int *);
void ispisi_postavu(FILE *, FUDBALER *, int, int, int, int);
void analiziraj_formaciju(char *, int *, int *, int *);

int main(int argc, char **argv) {
    FUDBALER fudbaleri[MAX_FUDBALERA];
    int n;

    if(argc != 4) {
        printf("Primer poziva programa: %s fudbaleri.txt postava.txt 4-3-3\n", argv[0]);
        exit(1);
    }

    FILE *pulazna = safe_fopen(argv[1], "r", 4);
    ucitaj_fudbalere(pulazna, fudbaleri, &n);
    fclose(pulazna);

    int odbrana, sredina, napad;
    analiziraj_formaciju(argv[3], &odbrana, &sredina, &napad);
    
    FILE *pizlazna = safe_fopen(argv[2], "w", 5);
    ispisi_postavu(pizlazna, fudbaleri, n, odbrana, sredina, napad);
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

void ucitaj_fudbalere(FILE *pulazna, FUDBALER *fudbaleri, int *pn) {
    int i = 0;

    while(fscanf(pulazna, "%s %s %d %s",
                 fudbaleri[i].ime,
                 fudbaleri[i].prezime,
                 &fudbaleri[i].broj_dresa,
                 fudbaleri[i].pozicija) != EOF) {
        i++;
    }

    *pn = i;
}

void ispisi_postavu(FILE *pizlazna, FUDBALER *fudbaleri, int n, int odbrana, int sredina, int napad) {
    int i, br_odbrana = 0, br_sredina = 0, br_napad = 0;

    for(i = 0;i < n;i++) {
        if(br_odbrana == odbrana && strcmp(fudbaleri[i].pozicija, "odbrana") == 0) {
            continue;
        } else if(br_sredina == sredina && strcmp(fudbaleri[i].pozicija, "sredina") == 0) {
            continue;
        } else if(br_napad == napad && strcmp(fudbaleri[i].pozicija, "napad") == 0) {
            continue;
        }

        fprintf(pizlazna, "%2d %s %c.\n",
                fudbaleri[i].broj_dresa,
                fudbaleri[i].prezime,
                fudbaleri[i].ime[0]);

        if(strcmp(fudbaleri[i].pozicija, "odbrana") == 0) {
            br_odbrana++;
        } else if(strcmp(fudbaleri[i].pozicija, "sredina") == 0) {
            br_sredina++;
        } else if(strcmp(fudbaleri[i].pozicija, "napad") == 0) {
            br_napad++;
        }
    }
}

void analiziraj_formaciju(char *formacija, int *podbrana, int *psredina, int *pnapad) {
    if(strlen(formacija) != MAX_POSTAVA - 1 || formacija[1] != '-' || formacija[3] != '-') {
        printf("Los format formacije, primer dobrog formata: 4-3-3\n");
        exit(2);
    }

    *podbrana = formacija[0] - '0';
    *psredina = formacija[2] - '0';
    *pnapad = formacija[4] - '0';

    if(*podbrana > 5 || *psredina > 5 || *pnapad > 5) {
        printf("Broj igraca na odredjenoj poziciji ne sme premasiti 5!\n");
        exit(3);
    }
}

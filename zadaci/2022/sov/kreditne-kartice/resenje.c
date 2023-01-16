#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_IME 21
#define MAX_PREZIME 31
#define MAX_BROJ_KARTICE 11

typedef struct kartica_st {
    char ime[MAX_IME];
    char prezime[MAX_PREZIME];
    char broj_kartice[MAX_BROJ_KARTICE];
    struct kartica_st *sledeci;
} KARTICA;

FILE *safe_fopen(char *, char *, int);
void ucitaj_kartice(FILE *, KARTICA **);
void ispisi_kartice(FILE *, FILE *, KARTICA *, int *, int *);

void inicijalizacija(KARTICA **);
KARTICA *napravi_cvor(char *, char *, char *);
void dodaj_na_kraj(KARTICA **, KARTICA *);
void obrisi_listu(KARTICA **);

int provera_broja(char *);

int main(char argc, char **argv) {
    KARTICA *glava;

    if(argc != 2) {
        printf("Primer poziva programa: %s kartice.txt\n", argv[0]);
        exit(1);
    }

    inicijalizacija(&glava);

    FILE *ulazna = safe_fopen(argv[1], "r", 3);
    ucitaj_kartice(ulazna, &glava);
    fclose(ulazna);

    FILE *izlazna_validni = safe_fopen("validne-kartice.txt", "w", 4);
    FILE *izlazna_nevalidni = safe_fopen("nevalidne-kartice.txt", "w", 5);
    int broj_validnih = 0, broj_nevalidnih = 0;
    ispisi_kartice(izlazna_validni, izlazna_nevalidni, glava, &broj_validnih, &broj_nevalidnih);
    printf("Izvestaj\n\n");
    printf("Broj validnih: %d\n", broj_validnih);
    printf("Sa greskom: %d\n", broj_nevalidnih);
    printf("Procenat uspesnosti: %.2lf%%\n", (double)broj_validnih / (broj_validnih + broj_nevalidnih) * 100);
    fclose(izlazna_validni);
    fclose(izlazna_nevalidni);

    obrisi_listu(&glava);

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

void ucitaj_kartice(FILE *pulazna, KARTICA **pglava) {
    char tmp_ime[MAX_IME];
    char tmp_prezime[MAX_PREZIME];
    char tmp_broj_kartice[MAX_BROJ_KARTICE];

    while(fscanf(pulazna, "%s %s %s",
                 tmp_ime,
                 tmp_prezime,
                 tmp_broj_kartice) != EOF) {
        KARTICA *novi = napravi_cvor(
            tmp_ime,
            tmp_prezime,
            tmp_broj_kartice);
        dodaj_na_kraj(pglava, novi);
    }

}

void ispisi_kartice(FILE *izlazna_validni, FILE *izlazna_nevalidni, KARTICA *glava,
                    int *pbroj_validnih, int *pbroj_nevalidnih) {
    KARTICA *tekuci = glava;
    FILE *izlazna;
    int validan_broj;

    while(tekuci != NULL) {
        if(provera_broja(tekuci->broj_kartice)) {
            izlazna = izlazna_validni;
            (*pbroj_validnih)++;
        } else {
            izlazna = izlazna_nevalidni;
            (*pbroj_nevalidnih)++;
        }

        fprintf(izlazna, "%-8s %-11s %s\n", tekuci->ime, tekuci->prezime, tekuci->broj_kartice);

        tekuci = tekuci->sledeci;
    }
}

void inicijalizacija(KARTICA **pglava) {
    *pglava = NULL;
}

KARTICA *napravi_cvor(char *ime, char *prezime, char *broj_kartice) {
    KARTICA *novi = (KARTICA *)malloc(sizeof(KARTICA));

    if(novi == NULL) {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(2);
    }

    strcpy(novi->ime, ime);
    strcpy(novi->prezime, prezime);
    strcpy(novi->broj_kartice, broj_kartice);
    novi->sledeci = NULL;

    return novi;
}

void dodaj_na_kraj(KARTICA **pglava, KARTICA *novi) {
    if(*pglava == NULL) {
        *pglava = novi;
    } else {
        KARTICA *tekuci = *pglava;

        while(tekuci->sledeci != NULL) {
            tekuci = tekuci->sledeci;
        }

        tekuci->sledeci = novi;
    }
}

void obrisi_listu(KARTICA **pglava) {
    KARTICA *tmp;

    while(*pglava != NULL) {
        tmp = *pglava;
        *pglava = (*pglava)->sledeci;
        tmp->sledeci = NULL;
        free(tmp);
    }
}

int provera_broja(char *broj_kartice) {
    int i, duzina = strlen(broj_kartice), suma = 0, je_drugi = 0;

    for(i = duzina - 1;i >= 0;i--) {
        int broj = broj_kartice[i] - '0';

        if(je_drugi) {
            broj *= 2;
        }

        // ako je broj dvocifren, ovo ce pomoci da se dobiju sume njegovih cifara (npr. 18 -> 1 + 8)
        // ako je jednocifren, broj / 10 ce biti 0, a broj % 10 ce biti sam broj
        suma += broj / 10;
        suma += broj % 10;

        je_drugi = !je_drugi;
    }

    return suma % 10 == 0;
}

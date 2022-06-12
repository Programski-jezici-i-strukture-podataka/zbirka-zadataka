#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NIZ 30

#define MAX_SIROVINA 31

typedef struct glas_st {
    char naziv_drzave[MAX_SIROVINA];
    unsigned glasovi_publike;
    unsigned glasovi_zirija;
    unsigned ukupno_glasova;
    struct glas_st *sledeci;
} GLAS;

FILE *safe_fopen(char *naziv, char *rezim, int kod_greske);
void ucitaj_glasove(FILE *ulazna, GLAS **pglava);
void ispisi_konacne_rezultate(FILE *izlazna, GLAS *glava);

void inicijalizacija(GLAS **pglava);
GLAS *napravi_cvor(char *naziv_drzave, unsigned glasovi_publike, unsigned glasovi_zirija);
void dodaj_sortirano(GLAS **pglava, GLAS *novi);
GLAS *najmanja_razlika_izmedju_glasova(GLAS *);
void obrisi_listu(GLAS **pglava);

int main(int argc, char **argv) {
    GLAS *glava;

    if(argc != 3) {
        printf("Primer poziva programa: %s glasanje.txt rezultati.txt\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    inicijalizacija(&glava);

    FILE *ulazna = safe_fopen(argv[1], "r", 2);
    ucitaj_glasove(ulazna, &glava);
    fclose(ulazna);

    FILE *izlazna = safe_fopen(argv[2], "w", 3);
    ispisi_konacne_rezultate(izlazna, glava);

    GLAS *najmanja_razlika_cvor = najmanja_razlika_izmedju_glasova(glava);
    fprintf(izlazna,
            "\nDrzava ucesnica sa najmanjom razlikom izmedju glasova publike(%u) i zirija(%u) je %s.\n",
            najmanja_razlika_cvor->glasovi_publike,
            najmanja_razlika_cvor->glasovi_zirija,
            najmanja_razlika_cvor->naziv_drzave
    );

    fclose(izlazna);

    obrisi_listu(&glava);

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

void ucitaj_glasove(FILE *pulazna, GLAS **pglava) {
    char tmp_naziv_drzave[MAX_SIROVINA];
    unsigned tmp_glasovi_publike;
    unsigned tmp_glasovi_zirija;

    while(fscanf(pulazna, "%s %u %u",
                 tmp_naziv_drzave,
                 &tmp_glasovi_publike,
                 &tmp_glasovi_zirija) != EOF) {
        GLAS *novi = napravi_cvor(tmp_naziv_drzave, tmp_glasovi_publike, tmp_glasovi_zirija);
        dodaj_sortirano(pglava, novi);
    }
}

void ispisi_konacne_rezultate(FILE *izlazna, GLAS *glava) {
    GLAS *tekuci = glava;
    int brojac = 1;

    while(tekuci != NULL) {
        fprintf(izlazna, "%2d. %-9s %3u %3u %3u\n", brojac, tekuci->naziv_drzave, 
                tekuci->ukupno_glasova, tekuci->glasovi_publike, tekuci->glasovi_zirija);

        tekuci = tekuci->sledeci;
        brojac++;
    }
}

void inicijalizacija(GLAS **pglava) {
    *pglava = NULL;
}

GLAS *napravi_cvor(char *naziv_drzave, unsigned glasovi_publike, unsigned glasovi_zirija) {
    GLAS *novi = (GLAS *)malloc(sizeof(GLAS));

    if(novi == NULL) {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(novi->naziv_drzave, naziv_drzave);
    novi->glasovi_publike = glasovi_publike;
    novi->glasovi_zirija = glasovi_zirija;
    novi->ukupno_glasova = glasovi_publike + glasovi_zirija;
    novi->sledeci = NULL;

    return novi;
}

void dodaj_sortirano(GLAS **pglava, GLAS *novi) {
    if(*pglava == NULL || (*pglava)->ukupno_glasova < novi->ukupno_glasova) {
        novi->sledeci = *pglava;
        *pglava = novi;
    } else {
        GLAS *tekuci = *pglava;

        while(tekuci->sledeci != NULL &&
              novi->ukupno_glasova < tekuci->sledeci->ukupno_glasova) {
            tekuci = tekuci->sledeci;
        }

        novi->sledeci = tekuci->sledeci;
        tekuci->sledeci = novi;
    }
}

GLAS *najmanja_razlika_izmedju_glasova(GLAS *glava) {
    GLAS *tekuci = glava;
    GLAS *najmanja_razlika_cvor = glava;
    unsigned najmanja_razlika = abs(glava->glasovi_publike - glava->glasovi_zirija);
    unsigned tekuci_razlika;

    while(tekuci != NULL) {
        tekuci_razlika = abs(tekuci->glasovi_publike - tekuci->glasovi_zirija);

        if(tekuci_razlika < najmanja_razlika) {
            najmanja_razlika = tekuci_razlika;
            najmanja_razlika_cvor = tekuci;
        }

        tekuci = tekuci->sledeci;
    }

    return najmanja_razlika_cvor;
}

void obrisi_listu(GLAS **pglava) {
    GLAS *tmp;

    while(*pglava != NULL) {
        tmp = *pglava;
        *pglava = (*pglava)->sledeci;
        tmp->sledeci = NULL;
        free(tmp);
    }
}


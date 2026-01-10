#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_IME 21
#define MAX_PREZIME 31

typedef struct kandidati_st {
    char ime[MAX_IME];
    char prezime[MAX_PREZIME];
    unsigned ostvareni_bodovi;
    struct kandidati_st *sledeci;
} KANDIDAT;

FILE *safe_fopen(char *, char *, int);
void ucitaj_kandidate(FILE *, KANDIDAT **);
void ispisi_preliminarnu_listu(FILE *, KANDIDAT *, unsigned);

void inicijalizacija(KANDIDAT **);
KANDIDAT *napravi_cvor(char *, char *, unsigned);
void dodaj_sortirano(KANDIDAT **, KANDIDAT *);
void konvertuj_brojeve_telefona(KANDIDAT *);
void obrisi_listu(KANDIDAT **);

int main(int argc, char **argv) {
    KANDIDAT *glava;

    if(argc != 4) {
        printf("Primer poziva: %s kandidati.txt preliminarna-lista.txt 5\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    inicijalizacija(&glava);

    FILE *ulazna = safe_fopen(argv[1], "r", 3);
    ucitaj_kandidate(ulazna, &glava);
    fclose(ulazna);

    unsigned broj_primljenih = atoi(argv[3]);
    FILE *izlazna = safe_fopen(argv[2], "w", 4);
    ispisi_preliminarnu_listu(izlazna, glava, broj_primljenih);
    fclose(izlazna);

    obrisi_listu(&glava);

    return EXIT_SUCCESS;
}

FILE *safe_fopen(char *name, char *mode, int error_code) {
    FILE *fp = fopen(name, mode);

    if(fp == NULL) {
        printf("Nije moguce otvoriti fajl %s!\n", name);
        exit(error_code);
    }

    return fp;
}

void ucitaj_kandidate(FILE *ulazna, KANDIDAT **pglava) {
    char tmp_ime[MAX_IME];
    char tmp_prezime[MAX_PREZIME];
    unsigned tmp_ostvareni_bodovi;

    while(fscanf(ulazna, "%s %s %u",
                 tmp_ime,
                 tmp_prezime,
                 &tmp_ostvareni_bodovi
          ) != EOF) {
        KANDIDAT *novi = napravi_cvor(tmp_ime, tmp_prezime, tmp_ostvareni_bodovi);
        dodaj_sortirano(pglava, novi);
    }
}

void ispisi_preliminarnu_listu(FILE *izlazna, KANDIDAT *glava, unsigned broj_primljenih) {
    unsigned redni_broj = 1;
    KANDIDAT *tekuci = glava;

    while(tekuci != NULL) {
        fprintf(izlazna, "%2u. %-7s %-7s %2u\n", 
            redni_broj, tekuci->ime, tekuci->prezime, tekuci->ostvareni_bodovi);

        if(redni_broj == broj_primljenih) {
            fprintf(izlazna, "------------------------------\n");
        }

        redni_broj++;
        tekuci = tekuci->sledeci;
    }
}

void inicijalizacija(KANDIDAT **pglava) {
    *pglava = NULL;
}

KANDIDAT *napravi_cvor(char *ime, char *prezime, unsigned ostvareni_bodovi) {
    KANDIDAT *novi = (KANDIDAT *) malloc(sizeof(KANDIDAT));

    if(novi == NULL) {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(2);
    }

    strcpy(novi->ime, ime);
    strcpy(novi->prezime, prezime);
    novi->ostvareni_bodovi = ostvareni_bodovi;

    novi->sledeci = NULL;

    return novi;
}

void dodaj_sortirano(KANDIDAT **pglava, KANDIDAT *novi) {
    if(*pglava == NULL ||
       (*pglava)->ostvareni_bodovi < novi->ostvareni_bodovi) {
        novi->sledeci = *pglava;
        *pglava = novi;
    } else {
        KANDIDAT *tekuci = *pglava;

        while(tekuci->sledeci != NULL &&
              tekuci->sledeci->ostvareni_bodovi > novi->ostvareni_bodovi) {
            tekuci = tekuci->sledeci;
        }

        novi->sledeci = tekuci->sledeci;
        tekuci->sledeci = novi;
    }
}

void obrisi_listu(KANDIDAT **pglava) {
    KANDIDAT *tmp;

    while(*pglava != NULL) {
        tmp = *pglava;
        *pglava = (*pglava)->sledeci;
        tmp->sledeci = NULL;
        free(tmp);
    }
}


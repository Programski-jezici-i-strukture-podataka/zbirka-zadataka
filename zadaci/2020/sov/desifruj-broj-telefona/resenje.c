#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_IME_PRUZAOCA 21
#define MAX_USLUGA 11
#define MAX_BROJ_TELEFONA 21

#define MAX_IME_IZL_DAT (13 + MAX_USLUGA)   // strlen("telefoni_") + MAX_USLUGA + strlen(".txt")

typedef struct imenik_st {
    char ime_pruzaoca[MAX_IME_PRUZAOCA];
    char usluga[MAX_USLUGA];
    char broj_telefona[MAX_BROJ_TELEFONA];
    struct imenik_st *sledeci;
} IMENIK;

FILE *safe_fopen(char *, char *, int);
void ucitaj_u_imenik(FILE *, IMENIK **);
void ispisi_po_tipu_usluge(FILE *, IMENIK *, char *);

void inicijalizacija(IMENIK **);
IMENIK *napravi_cvor(char *, char *, char *);
void dodaj_na_kraj(IMENIK **, IMENIK *);
void konvertuj_brojeve_telefona(IMENIK *);
void obrisi_listu(IMENIK **);

void desifruj_broj_telefona(char *);

int main(int argc, char **argv) {
    IMENIK *glava;

    if(argc != 3) {
        printf("Primer poziva: %s imenik.txt hrana\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    inicijalizacija(&glava);

    FILE *ulazna = safe_fopen(argv[1], "r", 3);
    ucitaj_u_imenik(ulazna, &glava);
    fclose(ulazna);

    konvertuj_brojeve_telefona(glava);

    char ime_izl_dat[MAX_IME_IZL_DAT];
    sprintf(ime_izl_dat, "telefoni-%s.txt", argv[2]);
    FILE *izlazna = safe_fopen(ime_izl_dat, "w", 4);
    ispisi_po_tipu_usluge(izlazna, glava, argv[2]);
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

void ucitaj_u_imenik(FILE *ulazna, IMENIK **pglava) {
    char tmp_ime_pruzaoca[MAX_IME_PRUZAOCA];
    char tmp_usluga[MAX_USLUGA];
    char tmp_broj_telefona[MAX_BROJ_TELEFONA];

    while(fscanf(ulazna, "%s %s %s",
                 tmp_ime_pruzaoca,
                 tmp_usluga,
                 tmp_broj_telefona
          ) != EOF) {
        IMENIK *novi = napravi_cvor(tmp_ime_pruzaoca, tmp_usluga, tmp_broj_telefona);
        dodaj_na_kraj(pglava, novi);
    }
}

void ispisi_po_tipu_usluge(FILE *izlazna, IMENIK *glava, char *usluga) {
    IMENIK *tekuci = glava;

    while(tekuci != NULL) {
        if(strcmp(tekuci->usluga, usluga) == 0) {
            fprintf(izlazna, "%-12s %s\n", tekuci->ime_pruzaoca, tekuci->broj_telefona);
        }

        tekuci = tekuci->sledeci;
    }
}

void inicijalizacija(IMENIK **pglava) {
    *pglava = NULL;
}

IMENIK *napravi_cvor(char *ime_pruzaoca, char *usluga, char *broj_telefona) {
    IMENIK *novi = (IMENIK *) malloc(sizeof(IMENIK));

    if(novi == NULL) {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(2);
    }

    strcpy(novi->ime_pruzaoca, ime_pruzaoca);
    strcpy(novi->usluga, usluga);
    strcpy(novi->broj_telefona, broj_telefona);

    novi->sledeci = NULL;

    return novi;
}

void dodaj_na_kraj(IMENIK **pglava, IMENIK *novi) {
    if(*pglava == NULL) {
        *pglava = novi;
    } else {
        IMENIK *tekuci = *pglava;

        while(tekuci->sledeci != NULL) {
            tekuci = tekuci->sledeci;
        }

        tekuci->sledeci = novi;
    }
}

void konvertuj_brojeve_telefona(IMENIK *glava) {
    IMENIK *tekuci = glava;

    while(tekuci != NULL) {
        desifruj_broj_telefona(tekuci->broj_telefona);
        tekuci = tekuci->sledeci;
    }
}

void obrisi_listu(IMENIK **pglava) {
    IMENIK *tmp;

    while(*pglava != NULL) {
        tmp = *pglava;
        *pglava = (*pglava)->sledeci;
        tmp->sledeci = NULL;
        free(tmp);
    }
}

void desifruj_broj_telefona(char *broj_telefona) {
    int i;

    for(i = 0; i < strlen(broj_telefona); i++) {
        switch(broj_telefona[i]) {
            case 'A': case 'B': case 'C':
              broj_telefona[i] = '2';
              break;
            case 'D': case 'E': case 'F':
              broj_telefona[i] = '3';
              break;
            case 'G': case 'H': case 'I':
              broj_telefona[i] = '4';
              break;
            case 'J': case 'K': case 'L':
              broj_telefona[i] = '5';
              break;
            case 'M': case 'N': case 'O':
              broj_telefona[i] = '6';
              break;
            case 'P': case 'Q': case 'R': case 'S':
              broj_telefona[i] = '7';
              break;
            case 'T': case 'U': case 'V':
              broj_telefona[i] = '8';
              break;
            case 'W': case 'X': case 'Y': case 'Z':
              broj_telefona[i] = '9';
              break;
        }
    }
}

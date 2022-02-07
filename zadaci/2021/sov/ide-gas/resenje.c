#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_IME 21
#define MAX_PREZIME 31

#define MAX_IZLAZNA_DAT 18 // mesec(9) + godina(4) + ".txt"(4) + '\0'(1)

typedef struct stambene_jedinice_st {
    char ime[MAX_IME];
    char prezime[MAX_PREZIME];
    unsigned kvadratura_stana;
    struct stambene_jedinice_st *sledeci;
} ST_JEDINICA;

FILE *safe_fopen(char *, char *, int);
void ucitaj_kandidate(FILE *, ST_JEDINICA **);
void ispisi_racune(FILE *, ST_JEDINICA *, double);

void inicijalizacija(ST_JEDINICA **);
ST_JEDINICA *napravi_cvor(char *, char *, unsigned);
void dodaj_na_kraj(ST_JEDINICA **, ST_JEDINICA *);
unsigned ukupna_kvadratura(ST_JEDINICA *);
void obrisi_listu(ST_JEDINICA **);

double potrosnja_po_stanu(unsigned, unsigned, double);
double uvecaj_za_porez(double, double);

int main(int argc, char **argv) {
    ST_JEDINICA *glava;

    if(argc != 5) {
        printf("Primer poziva: %s zgrada.txt decembar 2021 12510.54\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    inicijalizacija(&glava);

    FILE *ulazna = safe_fopen(argv[1], "r", 3);
    ucitaj_kandidate(ulazna, &glava);
    fclose(ulazna);

    double ukupna_potrosnja = atof(argv[4]);
    char izlazna_dat[MAX_IZLAZNA_DAT];
    strcpy(izlazna_dat, argv[2]);
    strcat(izlazna_dat, argv[3]);
    strcat(izlazna_dat, ".txt");
    FILE *izlazna = safe_fopen(izlazna_dat, "w", 4);
    ispisi_racune(izlazna, glava, ukupna_potrosnja);
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

void ucitaj_kandidate(FILE *ulazna, ST_JEDINICA **pglava) {
    char tmp_ime[MAX_IME];
    char tmp_prezime[MAX_PREZIME];
    unsigned tmp_kvadratura_stana;

    while(fscanf(ulazna, "%s %s %u",
                 tmp_ime,
                 tmp_prezime,
                 &tmp_kvadratura_stana
          ) != EOF) {
        ST_JEDINICA *novi = napravi_cvor(tmp_ime, tmp_prezime, tmp_kvadratura_stana);
        dodaj_na_kraj(pglava, novi);
    }
}

void ispisi_racune(FILE *izlazna, ST_JEDINICA *glava, double ukupna_potrosnja) {
    ST_JEDINICA *tekuci = glava;
    unsigned kvadratura_zgrade = ukupna_kvadratura(glava);

    while(tekuci != NULL) {
        double potrosnja = potrosnja_po_stanu(
                               tekuci->kvadratura_stana, kvadratura_zgrade, ukupna_potrosnja);
        double racun = uvecaj_za_porez(potrosnja, 10);
        fprintf(izlazna, "%-7s %-10s %.2lf\n", 
            tekuci->ime, tekuci->prezime, racun);

        tekuci = tekuci->sledeci;
    }
}

void inicijalizacija(ST_JEDINICA **pglava) {
    *pglava = NULL;
}

ST_JEDINICA *napravi_cvor(char *ime, char *prezime, unsigned kvadratura_stana) {
    ST_JEDINICA *novi = (ST_JEDINICA *) malloc(sizeof(ST_JEDINICA));

    if(novi == NULL) {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(2);
    }

    strcpy(novi->ime, ime);
    strcpy(novi->prezime, prezime);
    novi->kvadratura_stana = kvadratura_stana;

    novi->sledeci = NULL;

    return novi;
}

void dodaj_na_kraj(ST_JEDINICA **pglava, ST_JEDINICA *novi) {
    if(*pglava == NULL) {
        *pglava = novi;
    } else {
        ST_JEDINICA *tekuci = *pglava;

        while(tekuci->sledeci != NULL) {
            tekuci = tekuci->sledeci;
        }

        tekuci->sledeci = novi;
    }
}

unsigned ukupna_kvadratura(ST_JEDINICA *glava) {
    ST_JEDINICA *tekuci = glava;
    unsigned kvadratura_zgrade = 0;

    while(tekuci != NULL) {
        kvadratura_zgrade += tekuci->kvadratura_stana;
        tekuci = tekuci->sledeci;
    }

    return kvadratura_zgrade;
}

void obrisi_listu(ST_JEDINICA **pglava) {
    ST_JEDINICA *tmp;

    while(*pglava != NULL) {
        tmp = *pglava;
        *pglava = (*pglava)->sledeci;
        tmp->sledeci = NULL;
        free(tmp);
    }
}

double potrosnja_po_stanu(unsigned kv_stana, unsigned kv_zgrade, double ukupna_potrosnja) {
    return (double) kv_stana / kv_zgrade * ukupna_potrosnja;
}

double uvecaj_za_porez(double osnovica, double procenat_pdv) {
    return osnovica * (1 + procenat_pdv / 100);
}


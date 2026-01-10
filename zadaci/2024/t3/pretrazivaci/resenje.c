#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAZIV 21

typedef struct cvor_st {
    char naziv[MAX_NAZIV];
    float pr2010;
    float pr2015;
    float pr2020;
    struct cvor_st *sledeci;
} CVOR;

FILE *safe_fopen(char *ime, char *rezim, int kod_greske);
void inicijalizacija(CVOR **glava);
void ucitavanje(CVOR **glava, FILE *pf);
CVOR *napravi_cvor(char *ime, float p10, float p15, float p20);
void dodaj_na_kraj(CVOR **glava, CVOR *novi);
void ispis_pretraga(FILE *pf, CVOR *glava);
void ispis_najposecenijeg(CVOR *glava);
void obrisi_listu(CVOR **glava);

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Primer poziva programa: %s pretrazivaci.txt out.txt\n", argv[0]);
        exit(1);
    }

    CVOR *glava;
    FILE *ulazna, *izlazna;

    inicijalizacija(&glava);
    ulazna = safe_fopen(argv[1], "r", 2);
    ucitavanje(&glava, ulazna);
    fclose(ulazna);

    izlazna = safe_fopen(argv[2], "w", 3);
    ispis_pretraga(izlazna, glava);
    fclose(izlazna);

    ispis_najposecenijeg(glava);
    obrisi_listu(&glava);

    return 0;
}

FILE *safe_fopen(char *ime, char *rezim, int kod_greske) {
    FILE *pf = fopen(ime, rezim);

    if (pf == NULL) {
        printf("Nije otvoren %s", ime);
        exit(kod_greske);
    }

    return pf;
}

void inicijalizacija(CVOR **glava) {
    *glava = NULL;
}

void ucitavanje(CVOR **glava, FILE *pf) {
    char ime[MAX_NAZIV];
    float p10, p15, p20;
    
    while(fscanf(pf, "%s %f %f %f", ime, &p10, &p15, &p20) != EOF) {
        CVOR *novi = napravi_cvor(ime, p10, p15, p20);
        dodaj_na_kraj(glava, novi);
    }
}

CVOR *napravi_cvor(char *ime, float p10, float p15, float p20) {
    CVOR *novi = (CVOR *)malloc(sizeof(CVOR));

    if (novi == NULL) {
        printf("Nema dovoljno memorije!\n");
        exit(4);
    }

    strcpy(novi->naziv, ime);
    novi->pr2010 = p10;
    novi->pr2015 = p15;
    novi->pr2020 = p20;
    novi->sledeci = NULL;

    return novi;
}

void dodaj_na_kraj(CVOR **glava, CVOR *novi) {
    if (*glava == NULL) {
        *glava = novi;
    } else {
        CVOR *trenutni = *glava;
        while(trenutni->sledeci != NULL) {
            trenutni = trenutni->sledeci;
        }
        trenutni->sledeci = novi;
    }
}

void obrisi_listu(CVOR **glava) {
    while(*glava != NULL) {
        CVOR *trenutni = *glava;
        *glava = trenutni->sledeci;
        trenutni->sledeci = NULL;
        free(trenutni);
    }
}

void ispis_pretraga(FILE *pf, CVOR *glava) {
    CVOR *tr = glava;
    while(tr != NULL) {
        fprintf(pf, "%s %.2f\n", tr->naziv, tr->pr2010 * 1.2 / 100 + tr->pr2015 * 2.3 / 100 + tr->pr2020 * 3.4 / 100);
        tr = tr->sledeci;
    }
}

void ispis_najposecenijeg(CVOR *glava) {
    CVOR *trenutni = glava;
    CVOR *max2010 = glava;
    CVOR *max2015 = glava;
    CVOR *max2020 = glava;
    while(trenutni != NULL) {
        if (trenutni->pr2010 > max2010->pr2010) {
            max2010 = trenutni;
        }
        if (trenutni->pr2015 > max2015->pr2015) {
            max2015 = trenutni;
        }
        if (trenutni->pr2020 > max2020->pr2020) {
            max2020 = trenutni;
        }
        trenutni = trenutni->sledeci;
    }
    printf("Najposeceniji pretrazivac\n");
    printf("2010: %s\n2015: %s\n2020: %s\n", max2010->naziv, max2015->naziv, max2020->naziv);
}

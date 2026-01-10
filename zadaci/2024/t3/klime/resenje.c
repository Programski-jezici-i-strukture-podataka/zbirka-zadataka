#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAZIV 31
#define MAX_PROIZVODJAC 31
#define MAX_KLASA 5
#define MAX_SIZE 6

typedef struct cvor_st {
    char naziv[MAX_NAZIV];
    char proizvodjac[MAX_PROIZVODJAC];
    int cena;
    char klasa[MAX_KLASA];
    struct cvor_st *sledeci;
} CVOR;

FILE *safe_fopen(char *ime, char *rezim, int kod_greske);
void inicijalizacija(CVOR **glava);
void ucitavanje(CVOR **glava, FILE *pf);
CVOR *napravi_cvor(char *ime, char *pr, int cena, char *kl);
void dodaj_na_kraj(CVOR **glava, CVOR *novi);
void ispis_proizvodjaca(FILE *pf, CVOR *glava, char *pr);
void ispis_klasa(CVOR *glava);
void obrisi_listu(CVOR **glava);

int main(int argc, char **argv) {

    if (argc != 4) {
        printf("Primer poziva programa: %s klime.txt out.txt BOSCH\n", argv[0]);
        exit(1);
    }

    CVOR *glava;
    FILE *ulazna, *izlazna;

    inicijalizacija(&glava);
    ulazna = safe_fopen(argv[1], "r", 2);
    ucitavanje(&glava, ulazna);
    fclose(ulazna);

    izlazna = safe_fopen(argv[2], "w", 3);
    ispis_proizvodjaca(izlazna, glava, argv[3]);
    fclose(izlazna);

    ispis_klasa(glava);
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
    char ime[MAX_NAZIV], pr[MAX_PROIZVODJAC], kl[MAX_KLASA];
    int cena;
    
    while(fscanf(pf, "%s %s %d %s", ime, pr, &cena, kl) != EOF) {
        CVOR *novi = napravi_cvor(ime, pr, cena, kl);
        dodaj_na_kraj(glava, novi);
    }
}

CVOR *napravi_cvor(char *ime, char *pr, int cena, char *kl) {
    CVOR *novi = (CVOR *)malloc(sizeof(CVOR));

    if (novi == NULL) {
        printf("Nema dovoljno memorije!\n");
        exit(4);
    }

    strcpy(novi->naziv, ime);
    strcpy(novi->proizvodjac, pr);
    strcpy(novi->klasa, kl);
    novi->cena = cena;
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

void ispis_proizvodjaca(FILE *pf, CVOR *glava, char *pr) {
    CVOR *trenutni = glava;
    while(trenutni != NULL) {
        if (strcmp(trenutni->proizvodjac, pr) == 0) {
            fprintf(pf, "%s %d\n", trenutni->naziv, trenutni->cena);
        }
        trenutni = trenutni->sledeci;
    }
}

void ispis_klasa(CVOR *glava) {
    int klase[MAX_SIZE] = {0};
    int i;
    CVOR *trenutni = glava;
    while(trenutni != NULL) {
        if (strcmp(trenutni->klasa, "A+++") == 0) {
            klase[0]++;
        } else if (strcmp(trenutni->klasa, "A++") == 0) {
            klase[1]++;
        } else if (strcmp(trenutni->klasa, "A+") == 0) {
            klase[2]++;
        } else if (strcmp(trenutni->klasa, "A") == 0) {
            klase[3]++;
        } else if (strcmp(trenutni->klasa, "B") == 0) {
            klase[4]++;
        } else if (strcmp(trenutni->klasa, "C") == 0) {
            klase[5]++;
        } else {
            printf("Nepoznata energetska klasa %s, klime %s!\n", trenutni->klasa, trenutni->naziv);
            exit(5);
        }
        trenutni = trenutni->sledeci;
    }
    printf("Broj klimi po energetskoj klasi:\nA+++ %d\nA++ %d\nA+ %d\nA %d\nB %d\nC %d\n", klase[0],klase[1],klase[2],klase[3],klase[4],klase[5]);
}

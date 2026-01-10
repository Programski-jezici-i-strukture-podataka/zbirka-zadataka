#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NAZIV 41
#define MAX_SEARCH 4

typedef struct cvor_st {
    char naziv[MAX_NAZIV];
    int mem;
    char search[MAX_SEARCH];
    struct cvor_st *sledeci;
} CVOR;

FILE *safe_fopen(char *ime, char *rezim, int kod_greske);
void inicijalizacija(CVOR **glava);
void ucitavanje(CVOR **glava, FILE *pf);
CVOR *napravi_cvor(char *ime, int m, char *alg);
void dodaj_na_kraj(CVOR **glava, CVOR *novi);
void ispis_memorija(FILE *pf, CVOR *glava, int uneta_vel);
void ispis_trajanja(CVOR *glava, int uneta_vel);
void obrisi_listu(CVOR **glava);

int main(int argc, char **argv) {

    if (argc != 3) {
        printf("Primer poziva programa: %s strukture.txt 1000\n", argv[0]);
        exit(1);
    }

    CVOR *glava;
    FILE *ulazna, *izlazna;

    inicijalizacija(&glava);
    ulazna = safe_fopen(argv[1], "r", 2);
    ucitavanje(&glava, ulazna);
    fclose(ulazna);

    izlazna = safe_fopen("memorija.txt", "w", 3);
    ispis_memorija(izlazna, glava, atoi(argv[2]));
    fclose(izlazna);

    ispis_trajanja(glava, atoi(argv[2]));
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
    char ime[MAX_NAZIV], alg[MAX_SEARCH];
    int m;
    
    while(fscanf(pf, "%s %d %s", ime, &m, alg) != EOF) {
        CVOR *novi = napravi_cvor(ime, m, alg);
        dodaj_na_kraj(glava, novi);
    }
}

CVOR *napravi_cvor(char *ime, int m, char *alg) {
    CVOR *novi = (CVOR *)malloc(sizeof(CVOR));

    if (novi == NULL) {
        printf("Nema dovoljno memorije!\n");
        exit(4);
    }

    strcpy(novi->naziv, ime);
    strcpy(novi->search, alg);
    novi->mem = m;
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

void ispis_memorija(FILE *pf, CVOR *glava, int uneta_vel) {
    CVOR *tr = glava;
    while(tr != NULL) {
        fprintf(pf, "%s %.2lfkB\n", tr->naziv, tr->mem * uneta_vel / 1024.0);
        tr = tr->sledeci;
    }
}

void ispis_trajanja(CVOR *glava, int uneta_vel) {
    CVOR *trenutni = glava;
    printf("Prosecno vreme pretrage:\n");
    while(trenutni != NULL) {
        if(strcmp(trenutni->search, "1") == 0) {
            printf("%s - %d ns\n", trenutni->naziv, 5);
        } else if(strcmp(trenutni->search, "log") == 0) {
            printf("%s - %.2f ns\n", trenutni->naziv, 5.0 * log(uneta_vel));
        } else if(strcmp(trenutni->search, "n") == 0) {
            printf("%s - %d ns\n", trenutni->naziv, 5 * uneta_vel);
        }
        trenutni = trenutni->sledeci;
    }
}

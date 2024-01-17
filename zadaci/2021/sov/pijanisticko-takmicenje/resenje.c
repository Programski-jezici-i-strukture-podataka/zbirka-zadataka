#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_IME 21
#define MAX_PREZIME 31

typedef struct takmicar_st {
    char ime[MAX_IME];
    char prezime[MAX_PREZIME];
    unsigned broj_ostvarenih_poena;
    struct takmicar_st *levi;
    struct takmicar_st *desni;
} TAKMICAR;

FILE *safe_fopen(char *, char *, int);
void ucitaj_takmicare(FILE *, TAKMICAR **);
int ispisi_rezultate(FILE *, TAKMICAR *, int *);

void inicijalizacija(TAKMICAR **);
TAKMICAR *napravi_cvor(char *, char *, unsigned);
void dodaj_u_stablo(TAKMICAR **, TAKMICAR *);
void obrisi_stablo(TAKMICAR **);

int main(int argc, char **argv) {
    TAKMICAR *koren;

    if(argc != 3) {
        printf("Primer poziva programa: %s takmicari.txt rezultati.txt\n", argv[0]);
        return EXIT_FAILURE;
    }

    inicijalizacija(&koren);

    FILE *ulazna = safe_fopen(argv[1], "r", 3);
    ucitaj_takmicare(ulazna, &koren);
    fclose(ulazna);

    FILE *izlazna = safe_fopen(argv[2], "w", 4);
    int redni_broj = 0;     // Koristi nam da pratimo koje mesto u okviru nagrade je osvojio takmicar (prenosi se po referenci)
    
    // Mesto nam je potrebno samo dok prolazimo kroz stablo u rekurzivnim pozivima, necemo uzimati povratnu vrednost u main funkciji
    // Kada imamo takvu situaciju, odnosno pozivamo funkciju ciju povratnu vrednost necemo koristiti, 
    // u programskom jeziku C je dobra praksa je njen rezultat cast-ovati u void
    (void) ispisi_rezultate(izlazna, koren, &redni_broj);
    
    fclose(izlazna);

    obrisi_stablo(&koren);

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

void ucitaj_takmicare(FILE *ulazna, TAKMICAR **pkoren) {
    char tmp_ime[MAX_IME];
    char tmp_prezime[MAX_PREZIME];
    unsigned tmp_broj_ostvarenih_poena;

    while(fscanf(ulazna, "%s %s %u", tmp_ime, tmp_prezime, &tmp_broj_ostvarenih_poena) != EOF) {
        TAKMICAR *novi = napravi_cvor(tmp_ime, tmp_prezime, tmp_broj_ostvarenih_poena);
        dodaj_u_stablo(pkoren, novi);
    }
}

int ispisi_rezultate(FILE *izlazna, TAKMICAR *koren, int *predni_broj) {
    int mesto = 0;

    if(koren != NULL) {
        int mesto_levi = ispisi_rezultate(izlazna, koren->desni, predni_broj);
        mesto = mesto_levi;    // mesto je uvek 0, tako da je bitno samo sta mesto_levi ima u sebi (moze biti 0 ili neki veci broj)

        if(koren->broj_ostvarenih_poena >= 91 && koren->broj_ostvarenih_poena <= 100) {
            mesto = 1;
        } else if(koren->broj_ostvarenih_poena >= 81 && koren->broj_ostvarenih_poena <= 90) {
            if(mesto == 1) {
                *predni_broj = 0;   // reset rednog broja, jer smo izbrojali prve i prelazimo na druge nagrade
            }
            mesto = 2;
        } else {
            mesto = 3;  // pohvala (vrednost rednog broja nebitna)
        }

        switch(mesto) {
        case 1:
        case 2:
            (*predni_broj)++;
            fprintf(izlazna, "%-10s %-12s %d. %d.\n", koren->ime, koren->prezime, mesto, *predni_broj);
            break;
        case 3:
            fprintf(izlazna, "%-10s %-12s pohvala\n", koren->ime, koren->prezime);
            break;
        }

        int mesto_desni = ispisi_rezultate(izlazna, koren->levi, predni_broj);
        if(mesto_desni > mesto) {
            mesto = mesto_desni;
        }
    }

    return mesto;
}

void inicijalizacija(TAKMICAR **pkoren) {
    *pkoren = NULL;
}

TAKMICAR *napravi_cvor(char *ime, char *prezime, unsigned broj_ostvarenih_poena) {
    TAKMICAR *novi = (TAKMICAR *)malloc(sizeof(TAKMICAR));

    if(novi == NULL) {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(2);
    }

    strcpy(novi->ime, ime);
    strcpy(novi->prezime, prezime);
    novi->broj_ostvarenih_poena = broj_ostvarenih_poena;
    novi->levi = NULL;
    novi->desni = NULL;

    return novi;
}

void dodaj_u_stablo(TAKMICAR **pkoren, TAKMICAR *novi) {
    if(*pkoren == NULL) {
        *pkoren = novi;
    } else {
        if((*pkoren)->broj_ostvarenih_poena > novi->broj_ostvarenih_poena) {
            dodaj_u_stablo(&(*pkoren)->levi, novi);
        } else {
            dodaj_u_stablo(&(*pkoren)->desni, novi);
        }
    }
}

void obrisi_stablo(TAKMICAR **pkoren) {
    if(*pkoren != NULL) {
        obrisi_stablo(&(*pkoren)->levi);
        obrisi_stablo(&(*pkoren)->desni);
        free(*pkoren);
        *pkoren = NULL;
    }
}


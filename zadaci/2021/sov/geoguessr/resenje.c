#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KOR_IME 21

typedef struct pokusaj_st {
    char korisnicko_ime[MAX_KOR_IME];
    int rel_ud_pogotka;
    struct pokusaj_st *levi;
    struct pokusaj_st *desni;
} POKUSAJ;

FILE *safe_fopen(char *, char *, int);
void ucitaj_pokusaje(FILE *, POKUSAJ **);
void ispisi_rezultate(FILE *, POKUSAJ *);

void inicijalizacija(POKUSAJ **);
POKUSAJ *napravi_cvor(char *, int);
void dodaj_u_stablo(POKUSAJ **, POKUSAJ *);
POKUSAJ *pronadji_cvor(POKUSAJ *, char *);
void obrisi_stablo(POKUSAJ **);

int main(int argc, char **argv) {
    POKUSAJ *koren;

    if(argc != 5) {
        printf("Primer poziva: %s pokusaji.txt rezultati.txt Alatec Jeanite\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    inicijalizacija(&koren);

    FILE *ulazna = safe_fopen(argv[1], "r", 3);
    ucitaj_pokusaje(ulazna, &koren);
    fclose(ulazna);

    FILE *izlazna = safe_fopen(argv[2], "w", 4);
    ispisi_rezultate(izlazna, koren);
    POKUSAJ *prvi_igrac = pronadji_cvor(koren, argv[3]);
    POKUSAJ *drugi_igrac = pronadji_cvor(koren, argv[4]);
    if(prvi_igrac != NULL && drugi_igrac != NULL) {
        int raz_izm_pogotka = abs(prvi_igrac->rel_ud_pogotka - drugi_igrac->rel_ud_pogotka);
        fprintf(izlazna, "\nRazdaljina izmedju pogodataka igraca %s i %s je %dm.\n",
                prvi_igrac->korisnicko_ime, drugi_igrac->korisnicko_ime, raz_izm_pogotka);
    } else {
        fprintf(izlazna, "\nNe postoji bar jedan igrac od zadatih korisnickih imena!\n");
    }
    fclose(izlazna);

    obrisi_stablo(&koren);

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

void ucitaj_pokusaje(FILE *ulazna, POKUSAJ **pkoren) {
    char tmp_korisnicko_ime[MAX_KOR_IME];
    int tmp_rel_ud_pogotka;

    while(fscanf(ulazna, "%s %d",
                 tmp_korisnicko_ime,
                 &tmp_rel_ud_pogotka
          ) != EOF) {
        POKUSAJ *novi = napravi_cvor(tmp_korisnicko_ime, tmp_rel_ud_pogotka);
        dodaj_u_stablo(pkoren, novi);
    }
}

void ispisi_rezultate(FILE *izlazna, POKUSAJ *koren) {
    if(koren != NULL) {
        ispisi_rezultate(izlazna, koren->levi);
        fprintf(izlazna, "%4dm %s\n", koren->rel_ud_pogotka, koren->korisnicko_ime);
        ispisi_rezultate(izlazna, koren->desni);
    }
}

void inicijalizacija(POKUSAJ **pkoren) {
    *pkoren = NULL;
}

POKUSAJ *napravi_cvor(char *korisnicko_ime, int rel_ud_pogotka) {
    POKUSAJ *novi = (POKUSAJ *)malloc(sizeof(POKUSAJ));

    if(novi == NULL) {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(2);
    }

    strcpy(novi->korisnicko_ime, korisnicko_ime);
    novi->rel_ud_pogotka = rel_ud_pogotka;
    novi->levi = NULL;
    novi->desni = NULL;

    return novi;
}

void dodaj_u_stablo(POKUSAJ **pkoren, POKUSAJ *novi) {
    if(*pkoren == NULL) {
        *pkoren = novi;
    } else {
        if(strcmp((*pkoren)->korisnicko_ime, novi->korisnicko_ime) > 0) {
            dodaj_u_stablo(&(*pkoren)->levi, novi);
        } else {
            dodaj_u_stablo(&(*pkoren)->desni, novi);
        }
    }
}

POKUSAJ *pronadji_cvor(POKUSAJ *koren, char *korisnicko_ime) {
    POKUSAJ *nadjen = NULL;

    if(koren != NULL) {
        if(strcmp(koren->korisnicko_ime, korisnicko_ime) == 0) {
            nadjen = koren;
        } else {
            if(strcmp(koren->korisnicko_ime, korisnicko_ime) > 0) {
                pronadji_cvor(koren->levi, korisnicko_ime);
            } else {
                pronadji_cvor(koren->desni, korisnicko_ime);
            }
        }
    }
}

void obrisi_stablo(POKUSAJ **pkoren) {
    if(*pkoren != NULL) {
        obrisi_stablo(&(*pkoren)->levi);
        obrisi_stablo(&(*pkoren)->desni);
        free(*pkoren);
        *pkoren = NULL;
    }
}


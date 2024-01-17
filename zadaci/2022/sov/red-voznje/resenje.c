#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ODREDISTE 21
#define MAX_PREVOZNIK 31
#define MAX_VREME_POLASKA 6

typedef struct polazak_st {
    char odrediste[MAX_ODREDISTE];
    char vreme_polaska[MAX_VREME_POLASKA];
    char prevoznik[MAX_PREVOZNIK];
    double cena_karte;
    struct polazak_st *levi;
    struct polazak_st *desni;
} POLAZAK;

void inicijalizacija(POLAZAK **);
POLAZAK *napravi_cvor(char *, char *, char *, double);
void dodaj_u_stablo(POLAZAK **, POLAZAK *);
POLAZAK *najjeftiniji_pre_vremena(POLAZAK *, char *, char *);
void obrisi_stablo(POLAZAK **);

FILE *safe_fopen(char *, char *, int);
void ucitaj_polaske(FILE *, POLAZAK **);
void ispisi_polaske(FILE *, POLAZAK *);

int validacija_vremena(char *);

int main(int argc, char **argv) {
    POLAZAK *koren;

    if(argc != 5) {
        printf("Primer poziva programa: %s polasci.txt red-voznje.txt Zrenjanin 13.00\n", argv[0]);
        exit(1);
    }

    if(!validacija_vremena(argv[4])) {
        printf("Pogresan format vremena, primer dobrog formata: 13.00\n");
        exit(2);
    }

    inicijalizacija(&koren);

    FILE *ulazna = safe_fopen(argv[1], "r", 3);
    ucitaj_polaske(ulazna, &koren);
    fclose(ulazna);

    FILE *izlazna = safe_fopen(argv[2], "w", 4);
    ispisi_polaske(izlazna, koren);
    fclose(izlazna);

    POLAZAK *najjeftiniji = najjeftiniji_pre_vremena(koren, argv[3], argv[4]);
    if(najjeftiniji) {
        printf("Polazak pre %s casova za mesto %s sa najjeftinijom kartom je: %s %s %s %.2lf\n",
                argv[4], argv[3], najjeftiniji->odrediste, najjeftiniji->vreme_polaska, 
                najjeftiniji->prevoznik, najjeftiniji->cena_karte);
    } else {
        printf("Ne postoji polazak za mesto %s pre %s casova.\n", argv[3], argv[4]);
    }

    return 0;
}

void inicijalizacija(POLAZAK **pkoren) {
    *pkoren = NULL;
}

POLAZAK *napravi_cvor(char *odrediste, char *vreme_polaska, char *prevoznik, double cena_karte) {
    POLAZAK *novi = (POLAZAK *)malloc(sizeof(POLAZAK));

    if(novi == NULL) {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(5);
    }

    strcpy(novi->odrediste, odrediste);
    strcpy(novi->vreme_polaska, vreme_polaska);
    strcpy(novi->prevoznik, prevoznik);
    novi->cena_karte = cena_karte;
    novi->levi = NULL;
    novi->desni = NULL;

    return novi;
}

void dodaj_u_stablo(POLAZAK **pkoren, POLAZAK *novi) {
    if(*pkoren == NULL) {
        *pkoren = novi;
    } else {
        if(strcmp(novi->vreme_polaska, (*pkoren)->vreme_polaska) < 0) {
            dodaj_u_stablo(&(*pkoren)->levi, novi);
        } else {
            dodaj_u_stablo(&(*pkoren)->desni, novi);
        }
    }
}

POLAZAK *najjeftiniji_pre_vremena(POLAZAK *koren, char *odrediste, char *vreme) {
    POLAZAK *najjeftiniji = NULL;

    if(koren != NULL) {
        if(strcmp(koren->odrediste, odrediste) == 0 &&
           strcmp(koren->vreme_polaska, vreme) <= 0) {
            najjeftiniji = koren; 
        }

        POLAZAK *najjeftiniji_levi = najjeftiniji_pre_vremena(koren->levi, odrediste, vreme);
        if(najjeftiniji == NULL ||
           (najjeftiniji_levi != NULL && najjeftiniji_levi->cena_karte < najjeftiniji->cena_karte)) {
            najjeftiniji = najjeftiniji_levi;
        }

        POLAZAK *najjeftiniji_desni = najjeftiniji_pre_vremena(koren->desni, odrediste, vreme);
        if(najjeftiniji == NULL ||
           (najjeftiniji_desni != NULL && najjeftiniji_desni->cena_karte < najjeftiniji->cena_karte)) {
            najjeftiniji = najjeftiniji_desni;
        }
    }

    return najjeftiniji;
}

void obrisi_stablo(POLAZAK **pkoren) {
    if(*pkoren != NULL) {
        obrisi_stablo(&(*pkoren)->levi);
        obrisi_stablo(&(*pkoren)->desni);
        free(*pkoren);
        *pkoren = NULL;
    }
}

FILE *safe_fopen(char *ime, char *rezim, int kod_greske) {
    FILE *fp = fopen(ime, rezim);

    if(fp == NULL) {
        printf("Greska prilikom otvaranja %s datoteke!\n", ime);
        exit(kod_greske);
    }

    return fp;
}

void ucitaj_polaske(FILE *pulazna, POLAZAK **pkoren) {
    char tmp_odrediste[MAX_ODREDISTE];
    char tmp_vreme_polaska[MAX_VREME_POLASKA];
    char tmp_prevoznik[MAX_PREVOZNIK];
    double tmp_cena_karte;

    while(fscanf(pulazna, "%s %s %s %lf",
                 tmp_odrediste,
                 tmp_vreme_polaska,
                 tmp_prevoznik,
                 &tmp_cena_karte) != EOF) {
        POLAZAK *novi = napravi_cvor(
            tmp_odrediste,
            tmp_vreme_polaska,
            tmp_prevoznik,
            tmp_cena_karte);
        dodaj_u_stablo(pkoren, novi);
    }

}

void ispisi_polaske(FILE *izlazna, POLAZAK *koren) {
    if(koren != NULL) {
        ispisi_polaske(izlazna, koren->levi);
        fprintf(izlazna, "%9s %5s %-15s %7.2lf\n",
                koren->odrediste,
                koren->vreme_polaska,
                koren->prevoznik,
                koren->cena_karte);
        ispisi_polaske(izlazna, koren->desni);
    }
}

int validacija_vremena(char *vreme) {
    int sat, minut;

    if(strlen(vreme) != 5 || vreme[2] != '.') return 0;

    sat = (vreme[0] - '0') * 10;
    sat += vreme[1] - '0';

    if(sat >= 24) return 0;

    minut = (vreme[3] - '0') * 10;
    minut += vreme[4] - '0';

    if(minut >= 60) return 0;

    return 1;
}

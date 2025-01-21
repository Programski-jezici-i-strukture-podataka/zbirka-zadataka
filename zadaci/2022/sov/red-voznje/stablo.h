#ifndef STABLO_H
#define STABLO_H

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
void obrisi_stablo(POLAZAK **);

#endif

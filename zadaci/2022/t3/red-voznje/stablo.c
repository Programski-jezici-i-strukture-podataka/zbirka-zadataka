#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stablo.h"

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

void obrisi_stablo(POLAZAK **pkoren) {
    if(*pkoren != NULL) {
        obrisi_stablo(&(*pkoren)->levi);
        obrisi_stablo(&(*pkoren)->desni);
        free(*pkoren);
        *pkoren = NULL;
    }
}

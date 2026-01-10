#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

void init(CVOR** glava) {
    *glava = NULL;
}

CVOR* create_node(char* kategorija, char* naziv, float cena, float povrsina) {
    CVOR* tmp = malloc(sizeof(CVOR));
    if(tmp==NULL)
    {
        printf("Ne moze se zauzeti memorija\n");
        exit(3);
    }
    strcpy(tmp->kategorija, kategorija);
    strcpy(tmp->naziv, naziv);
    tmp->cena = cena;
    tmp->ukupna_cena = cena * povrsina;
    tmp->sledeci = NULL;
    return tmp; 
}

void add_sorted(CVOR** glava, CVOR* novi) {

   CVOR* trenutni;
    if(*glava==NULL || (*glava)->cena >= novi->cena) 
    {
        novi->sledeci = *glava;
        *glava = novi;
    } else 
    {
        trenutni = *glava;
        while(trenutni->sledeci!=NULL && trenutni->sledeci->cena < novi->cena)
        {
            trenutni = trenutni->sledeci;
        }
        novi->sledeci = trenutni->sledeci;
        trenutni->sledeci = novi;
    }
}

void clear(CVOR** glava) {
    CVOR *tmp;
    while(*glava != NULL)
    {
        tmp = *glava;
        *glava = (*glava)->sledeci;
        tmp->sledeci = NULL;
        free(tmp);
    }
}

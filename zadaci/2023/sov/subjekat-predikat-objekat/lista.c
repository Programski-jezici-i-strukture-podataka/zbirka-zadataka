#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "lista.h"

void inicijalizacija(REC **pglava)
{
    *pglava = NULL;
}

REC *napravi_cvor(char *rec, char *vrsta)
{
    REC *novi = (REC *)malloc(sizeof(REC));

    if(novi == NULL)
    {
        printf("Greska prilikom zauzimanja memorije!\n");
        exit(2);
    }

    strcpy(novi->rec, rec);
    strcpy(novi->vrsta, vrsta);
    novi->sledeci = NULL;

    return novi;
}

void dodaj_na_kraj(REC **pglava, REC *novi)
{
    if(*pglava == NULL)
    {
        *pglava = novi;
    }
    else
    {
        REC *tekuci = *pglava;

        while(tekuci->sledeci != NULL)
        {
            tekuci = tekuci->sledeci;
        }

        tekuci->sledeci = novi;
    }
}

void obrisi_listu(REC **pglava)
{
    REC *tmp;

    while(*pglava != NULL)
    {
        tmp = *pglava;
        *pglava = (*pglava)->sledeci;
        tmp->sledeci = NULL;
        free(tmp);
    }
}

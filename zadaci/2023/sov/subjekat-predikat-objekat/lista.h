#ifndef LISTA_H
#define LISTA_H

#define MAX_REC 21
#define MAX_VRSTA 9

typedef struct rec_st
{
    char rec[MAX_REC];
    char vrsta[MAX_VRSTA];
    struct rec_st *sledeci;
} REC;

void inicijalizacija(REC **);
REC *napravi_cvor(char *, char *);
void dodaj_na_kraj(REC **, REC *);
void obrisi_listu(REC **);

#endif

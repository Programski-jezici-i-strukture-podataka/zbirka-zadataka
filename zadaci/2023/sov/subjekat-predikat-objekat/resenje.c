#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_REC 21
#define MAX_VRSTA 9

#define MAX_NAZIV_IZLAZNE 11

typedef struct rec_st
{
    char rec[MAX_REC];
    char vrsta[MAX_VRSTA];
    struct rec_st *sledeci;
} REC;

FILE *safe_fopen(char *, char *, int);
void ucitaj_reci(FILE *, REC **);
void ispisi_recenice(FILE *, REC *);

void inicijalizacija(REC **);
REC *napravi_cvor(char *, char *);
void dodaj_na_kraj(REC **, REC *);
int prebroj_vrstu(REC *, char *);
void obrisi_listu(REC **);

int main(int argc, char **argv)
{
    REC *glava;

    if(argc != 3)
    {
        printf("Primer poziva programa: %s reci.txt recenice.txt\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    inicijalizacija(&glava);

    FILE *ulazna = safe_fopen(argv[1], "r", 3);
    ucitaj_reci(ulazna, &glava);
    fclose(ulazna);

    FILE *izlazna = safe_fopen(argv[2], "w", 4);
    ispisi_recenice(izlazna, glava);
    fclose(izlazna);

    int broj_subjekata = prebroj_vrstu(glava, "subjekat");
    int broj_predikata = prebroj_vrstu(glava, "predikat");
    int broj_objekata = prebroj_vrstu(glava, "objekat");

    printf("Od %d subjekta, %d predikata i %d objekta moguce je sastaviti %d recenica.\n",
        broj_subjekata, broj_predikata, broj_objekata, broj_subjekata * broj_predikata * broj_objekata);

    obrisi_listu(&glava);

    return EXIT_SUCCESS;
}

FILE *safe_fopen(char *naziv, char *rezim, int kod_greske)
{
    FILE *fp = fopen(naziv, rezim);

    if(fp == NULL)
    {
        printf("Datoteka %s nije uspesno otvorena!\n", naziv);
        exit(kod_greske);
    }

    return fp;
}

void ucitaj_reci(FILE *ulazna, REC **pglava)
{
    char tmp_rec[MAX_REC];
    char tmp_vrsta[MAX_VRSTA];
    REC *novi;

    while(fscanf(ulazna, "%s %s", tmp_rec, tmp_vrsta) != EOF)
    {
        novi = napravi_cvor(tmp_rec, tmp_vrsta);
        dodaj_na_kraj(pglava, novi);
    }
}

void ispisi_recenice(FILE *izlazna, REC *glava)
{
    REC *tekuci_subjekat = glava;
    REC *tekuci_predikat;
    REC *tekuci_objekat;
    char subjekat[MAX_REC];
    char predikat[MAX_REC];
    char objekat[MAX_REC];

    while(tekuci_subjekat != NULL)
    {
        if(strcmp(tekuci_subjekat->vrsta, "subjekat") == 0)
        {
            tekuci_predikat = glava;
            
            while(tekuci_predikat != NULL)
            {
                if(strcmp(tekuci_predikat->vrsta, "predikat") == 0)
                {
                    tekuci_objekat = glava;
                    
                    while(tekuci_objekat != NULL)
                    {
                        if(strcmp(tekuci_objekat->vrsta, "objekat") == 0)
                        {
                            strcpy(subjekat, tekuci_subjekat->rec);
                            strcpy(predikat, tekuci_predikat->rec);
                            strcpy(objekat, tekuci_objekat->rec);
                            predikat[0] += 32;
                            objekat[0] += 32;
                            fprintf(izlazna, "%s %s %s.\n", subjekat, predikat, objekat);
                        }
                        
                        tekuci_objekat = tekuci_objekat->sledeci;
                    }
                }

                tekuci_predikat = tekuci_predikat->sledeci;
            }
        }

        tekuci_subjekat = tekuci_subjekat->sledeci;
    }
}

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

int prebroj_vrstu(REC *glava, char *vrsta)
{
    REC *tekuci = glava;
    int broj = 0;

    while(tekuci != NULL)
    {
        if(strcmp(tekuci->vrsta, vrsta) == 0)
        {
            broj++;
        }

        tekuci = tekuci->sledeci;
    }

    return broj;
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

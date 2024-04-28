#include <stdio.h>
#include <stdlib.h>

#define MAX_IME 31
#define MAX_DRZAVA 10

typedef struct drzava_st
{
    char drzava[MAX_IME];
    int stanovnistvo;
    float povrsina;
} DRZAVA;

FILE *safe_fopen(char *, char *, int);
void ucitavanje(FILE *, DRZAVA *, int *);
void ispisi_gustine(FILE *, DRZAVA *, int);

int main()
{
    DRZAVA drzave[MAX_DRZAVA];
    int n;
    
    FILE *ulazna, *izlazna;
    ulazna = safe_fopen("primer.txt", "r", 1);
    ucitavanje(ulazna, drzave, &n);
    fclose(ulazna);
    
    izlazna = safe_fopen("gustina.txt", "w", 2);
    ispisi_gustine(izlazna, drzave, n);
    fclose(izlazna);

    return 0;
}

FILE *safe_fopen(char *ime, char *rezim, int kod_greske)
{
    FILE *pf = fopen(ime, rezim);
    
    if (pf == NULL)
    {
        printf("Nije uspesno pronadjena datoteka.\n");
        exit(kod_greske);
    }
    
    return pf;
}

void ucitavanje(FILE *ulazna, DRZAVA *d, int *pn)
{
    int i = 0;
    
    while(fscanf(ulazna, "%s %d %f", d[i].drzava, &d[i].stanovnistvo, &d[i].povrsina) != EOF)
    {
        i++;
    }
    
    *pn = i;
}

void ispisi_gustine(FILE *izlazna, DRZAVA *d, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        fprintf(izlazna, "%s %.2lf\n", d[i].drzava, d[i].stanovnistvo / d[i].povrsina);  
    }
}

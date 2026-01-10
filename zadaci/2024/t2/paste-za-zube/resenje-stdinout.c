#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASTA 20
#define MAX_NAZIV 31
#define MAX_DECIJA 3
#define MAX_SREDJEN_NAZIV 39

typedef struct pasta_st 
{
    char naziv[MAX_NAZIV];
    double cena;
    int velicina;
    char decija[MAX_DECIJA];
    char pun_naziv[MAX_SREDJEN_NAZIV];
} PASTA;

void ucitaj_paste(PASTA *, int *);
double suma_cena(PASTA *, int);
double prosek_cena(PASTA *, int);
void ispisi_vece(PASTA *, int, int);
void sredjeni_nazivi(PASTA *, int);

int main(int argc, char **argv) 
{

    PASTA paste[MAX_PASTA];
    int n, trazena_velicina;
    double prosek;

    if(argc != 2) 
    {
        printf("Primer poziva: %s 100\n", argv[0]);
        exit(1);
    }

    ucitaj_paste(paste, &n);
    
    prosek = prosek_cena(paste, n);
    printf("Prosecna pasta za zube kosta: %.2lf dinara.\n", prosek);
    
    trazena_velicina = atoi(argv[1]);
    ispisi_vece(paste, n, trazena_velicina);
    
    sredjeni_nazivi(paste, n);
    
    return 0;
}

void ucitaj_paste(PASTA *p, int *pn) 
{
    int i;

    do {
        scanf("%d", pn);
    } while(*pn <= 0 || *pn > MAX_PASTA);

    for(i = 0; i < *pn; i++) 
    {
        scanf("%s %lf %d %s", p[i].naziv, &p[i].cena, &p[i].velicina, p[i].decija);
    }
    
    *pn = i;
}

double suma_cena(PASTA *p, int n) {
    int i;
    double suma = 0;
    
    for(i = 0; i < n; i++) 
    {
        suma += p[i].cena;
    }
    
    return suma;
}

double prosek_cena(PASTA *p, int n) {
    return suma_cena(p, n) / n;
}

void ispisi_vece(PASTA *p, int n, int velicina) {
    int i, nadjena = 0;
    PASTA *najjeftinija = NULL;
    
    printf("Paste za zube od bar %dml: ", velicina);
    for(i = 0; i < n; i++) 
    {
        if(p[i].velicina > velicina) 
        {
            printf("%s ", p[i].naziv);
            nadjena = 1;
            if (najjeftinija == NULL || najjeftinija->cena > p[i].cena)
            {
                najjeftinija = &p[i];
            }
        }
    }
    printf("\n");
    if (nadjena)
    {
        printf("Najjefinija od njih je: %s!\n", najjeftinija->naziv);
    }
    else
    {
        printf("Nije nadjena pasta za zube veca od unete velicine!\n");
        exit(2);
    }
}

void sredjeni_nazivi(PASTA *p, int n) {
    int i, j;
    for(i = 0; i < n; i++) 
    {
        strcpy(p[i].pun_naziv, p[i].naziv);
        for(j = 0; j < strlen(p[i].pun_naziv); j++) 
        {
            if (p[i].pun_naziv[j] >= 'a' && p[i].pun_naziv[j] <= 'z') 
            {
                p[i].pun_naziv[j] -= 32;
            }
            if (p[i].pun_naziv[j] == '_') 
            {
                p[i].pun_naziv[j] = ' ';
            }
        }
        if (strcmp(p[i].decija, "da") == 0) 
        {
            strcat(p[i].pun_naziv, " za decu");
        }
        puts(p[i].pun_naziv);
    }
}

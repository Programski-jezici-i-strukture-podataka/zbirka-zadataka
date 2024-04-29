#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_IME 15

#define MAX_IGRACA 20

typedef struct igrac_st
{
    char ime[MAX_IME];
    int poena;
    int skokova;
    int asistencija;
    int utakmica;
    double efikasnost;
} IGRAC;

void ucitaj_igrace(IGRAC *, int *);
void ispisi_igrace(IGRAC *, int, double);
void sracunaj_efikasnosti(IGRAC *, int);
void sortiraj_igrace(IGRAC *, int);
void obradi_imena(IGRAC *, int, int);
double sracunaj_prosek(IGRAC *, int);

int main(int argc, char **argv)
{
    IGRAC igraci[MAX_IGRACA];
    int n;

    if(argc != 2)
    {
        printf("Primer poziva programa: %s 50\n", argv[0]);
        exit(1);
    }

    ucitaj_igrace(igraci, &n);
    sracunaj_efikasnosti(igraci, n);
    double prosek_efikasnosti = sracunaj_prosek(igraci, n);
    int min_broj_utakmica = atoi(argv[1]);
    sortiraj_igrace(igraci,n);
    obradi_imena(igraci,n, min_broj_utakmica);
    ispisi_igrace(igraci, n, prosek_efikasnosti);
    printf("\nProsecna efikasnost igraca je: %.2lf\n", prosek_efikasnosti);
    return 0;
}

void obradi_imena(IGRAC *igraci,int n, int min_broj_utakmica)
{
    int i;
    bool najbolji_dodeljen = false;
    for (i = 0;i < n;i++)
    {   
        if(igraci[i].utakmica < min_broj_utakmica)
        {
            strcat(igraci[i].ime, "(-)");
        }
        else
        {
            if(!najbolji_dodeljen)
            {
                strcat(igraci[i].ime, "(*)");
                najbolji_dodeljen = true;
            }
        }
    }
}

void sortiraj_igrace(IGRAC *igraci,int n)
{
    IGRAC tmp;
    int i, j, min_idx;
    for(i = 0;i < n - 1;i++)
    {
        min_idx = i;
        for(j = i + 1;j < n;j++)
        {
            if(igraci[min_idx].efikasnost < igraci[j].efikasnost)
            {
                min_idx = j;
            }
        }
        if(min_idx != i)
        {
            tmp = igraci[i];
            igraci[i] = igraci[min_idx];
            igraci[min_idx] = tmp;
        }
    }
}

void sracunaj_efikasnosti(IGRAC *igraci,int n)
{
    int i;
    for (i = 0;i < n;i++)
    {   
        igraci[i].efikasnost = (igraci[i].poena+igraci[i].skokova+igraci[i].asistencija)/(double)igraci[i].utakmica;
    }
}

double sracunaj_prosek(IGRAC *igraci, int n)
{
    int i;
    double suma = 0;
    for (i = 0;i < n;i++)
    {
        suma += igraci[i].efikasnost;
    }
    
    return suma/n;
}

void ucitaj_igrace(IGRAC *igraci, int *pn)
{
    int i;

    do
    {
        scanf("%d", pn);
    } while (*pn <= 0 || *pn > MAX_IGRACA);

    for (i = 0;i < *pn;i++)
    {
        scanf("%s %d %d %d %d",
            igraci[i].ime,
            &igraci[i].poena,
            &igraci[i].skokova,
            &igraci[i].asistencija,
            &igraci[i].utakmica);
    }
}

void ispisi_igrace(IGRAC *igraci, int n, double prosek)
{
    int i;
    for(i = 0;i < n;i++) 
    {
        printf("%12s %10d %10d %10d %10d %10.2lf",
        igraci[i].ime,
        igraci[i].poena,
        igraci[i].skokova,
        igraci[i].asistencija,
        igraci[i].utakmica,
        igraci[i].efikasnost);
        printf("\n");
    }
}


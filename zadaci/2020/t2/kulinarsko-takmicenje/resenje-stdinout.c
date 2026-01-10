#include <stdio.h>
#include <stdlib.h>

#define MAX_DRZAVA 21
#define MAX_VRSTA_HRANE 21

#define MAX_SIZE 30

typedef struct tim_st
{
    char drzava[MAX_DRZAVA];
    char vrsta_hrane[MAX_VRSTA_HRANE];
    double ocena_publike;
    double ocena_zirija;
} TIM;

void ucitaj_timove(TIM *t, int *pn);
void ispisi_izabrane(TIM *t, int n, double prag);
double prosek_izabranih_timova(TIM *t, int n, double prag);
int tim_je_prosao(double ocena_publike, double ocena_zirija, double prag);

int main(int argc, char **argv)
{
    TIM timovi[MAX_SIZE];
    int n;

    if(argc != 2)
    {
        printf("Primer poziva: %s 13.5\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ucitaj_timove(timovi, &n);
    printf("\n\n");
    double prag = atof(argv[1]);
    ispisi_izabrane(timovi, n, prag);

    printf("Prosecna ocena timova koji su prosli u sledeci krug takmicenja je: %.2f\n", 
        prosek_izabranih_timova(timovi, n, prag));

    return EXIT_SUCCESS;
}

void ucitaj_timove(TIM *t, int *pn)
{
    do
    {
        printf("Unesite broj timova: ");
        scanf("%d", pn);
    } while (*pn <= 0 || *pn > MAX_SIZE);

    int i;

    for(i = 0;i < *pn;i++)
    {
        printf("%d. tim: ", i + 1);
        scanf("%s %s %lf %lf", 
            t[i].drzava,
            t[i].vrsta_hrane,
            &t[i].ocena_publike,
            &t[i].ocena_zirija);
    }
}

void ispisi_izabrane(TIM *t, int n, double prag)
{
    int i;

    for(i = 0;i < n;i++)
    {
        if(tim_je_prosao(t[i].ocena_publike, t[i].ocena_zirija, prag))
        {
            printf("%s %s %.2lf %.2lf\n",
                t[i].drzava,
                t[i].vrsta_hrane,
                t[i].ocena_publike,
                t[i].ocena_zirija);
        }
    }
}

double prosek_izabranih_timova(TIM *t, int n, double prag)
{
    int i, brojac = 0;
    double suma = 0.0;

    for(i = 0;i < n;i++)
    {
        if(tim_je_prosao(t[i].ocena_publike, t[i].ocena_zirija, prag))
        {
            suma += t[i].ocena_publike + t[i].ocena_zirija;
            brojac++;
        }
    }

    return suma / brojac;
}

int tim_je_prosao(double ocena_publike, double ocena_zirija, double prag)
{
    return ocena_publike + ocena_zirija >= prag;
}

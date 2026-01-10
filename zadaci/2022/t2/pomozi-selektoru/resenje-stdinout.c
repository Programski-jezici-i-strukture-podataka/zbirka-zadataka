#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define MAX_IME 21
#define MAX_PREZIME 31
#define MAX_POZICIJA 11

#define MAX_POSTAVA 6

#define MAX_FUDBALERA 20

typedef struct fudbaler_st
{
    char ime[MAX_IME];
    char prezime[MAX_PREZIME];
    int broj_dresa;
    char pozicija[MAX_POZICIJA];
} FUDBALER;

void ucitaj_fudbalere(FUDBALER *, int *);
void ispisi_postavu(FUDBALER *, int, int, int, int);
void analiziraj_formaciju(char *, int *, int *, int *);

int main(int argc, char **argv)
{
    FUDBALER fudbaleri[MAX_FUDBALERA];
    int n;

    if (argc != 2)
    {
        printf("Primer poziva programa: %s 4-3-3 < fudbaleri-stdinout.txt\n", argv[0]);
        exit(1);
    }

    ucitaj_fudbalere(fudbaleri, &n);

    int odbrana, sredina, napad;
    analiziraj_formaciju(argv[1], &odbrana, &sredina, &napad);

    printf("\n\n");
    ispisi_postavu(fudbaleri, n, odbrana, sredina, napad);

    return 0;
}

void ucitaj_fudbalere(FUDBALER *fudbaleri, int *pn)
{
    int i;

    do
    {
        printf("Unesite broj fudbalera: ");
        scanf("%d", pn);
    } while (*pn <= 0 || *pn > MAX_FUDBALERA);

    for (i = 0; i < *pn; i++)
    {
        printf("%d. fudbaler: ", i + 1);
        scanf("%s %s %d %s",
              fudbaleri[i].ime,
              fudbaleri[i].prezime,
              &fudbaleri[i].broj_dresa,
              fudbaleri[i].pozicija);
    }
}

void ispisi_postavu(FUDBALER *fudbaleri, int n, int odbrana, int sredina, int napad)
{
    int i, br_odbrana = 0, br_sredina = 0, br_napad = 0;

    for (i = 0; i < n; i++)
    {
        if (br_odbrana == odbrana && strcmp(fudbaleri[i].pozicija, "odbrana") == 0)
        {
            continue;
        }
        else if (br_sredina == sredina && strcmp(fudbaleri[i].pozicija, "sredina") == 0)
        {
            continue;
        }
        else if (br_napad == napad && strcmp(fudbaleri[i].pozicija, "napad") == 0)
        {
            continue;
        }

        printf("%2d %s %c.\n",
               fudbaleri[i].broj_dresa,
               fudbaleri[i].prezime,
               fudbaleri[i].ime[0]);

        if (strcmp(fudbaleri[i].pozicija, "odbrana") == 0)
        {
            br_odbrana++;
        }
        else if (strcmp(fudbaleri[i].pozicija, "sredina") == 0)
        {
            br_sredina++;
        }
        else if (strcmp(fudbaleri[i].pozicija, "napad") == 0)
        {
            br_napad++;
        }
    }
}

void analiziraj_formaciju(char *formacija, int *podbrana, int *psredina, int *pnapad)
{
    if (strlen(formacija) != MAX_POSTAVA - 1 || formacija[1] != '-' || formacija[3] != '-')
    {
        printf("Los format formacije, primer dobrog formata: 4-3-3\n");
        exit(2);
    }

    *podbrana = formacija[0] - '0';
    *psredina = formacija[2] - '0';
    *pnapad = formacija[4] - '0';

    if (*podbrana > 5 || *psredina > 5 || *pnapad > 5)
    {
        printf("Broj igraca na odredjenoj poziciji ne sme premasiti 5!\n");
        exit(3);
    }
}

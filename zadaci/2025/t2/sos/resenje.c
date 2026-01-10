#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KOD 5

#define MAX_SIZE 30

#define MAX_KODNA_REC 51
#define MAX_REC 51

typedef struct morzeov_kod_st
{
    char slovo;
    char kod[MAX_KOD];
} MORZEOV_KOD;

FILE *safe_fopen(char *ime, char *rezim, int kod_greske);
void ucitaj_kodove(FILE *ulazna, MORZEOV_KOD *MORZEOV_KODovi, int *pn);
void dekodiraj_rec(MORZEOV_KOD *MORZEOV_KODovi, int n, char *MORZEOV_KODna_rec, int duzina_MORZEOV_KODne_reci, char *rec);

int main(int argc, char **argv)
{
    MORZEOV_KOD kodovi[MAX_SIZE];
    int n;

    if(argc != 3)
    {
        printf("Primer poziva: %s kodovi.txt poruka.txt\n", argv[0]);
        exit(2);
    }

    FILE *ulazna = safe_fopen(argv[1], "r", 3);
    ucitaj_kodove(ulazna, kodovi, &n);
    fclose(ulazna);

    char kodna_rec[MAX_KODNA_REC] = "";
    char rec[MAX_REC];

    // ... --- ... SOS
    // - .- ...    TAS 
    // .--. .- ... PAS
    // -- --- ...  MAS

    FILE *izlazna = safe_fopen(argv[2], "w", 4);
    printf("Uneti kodirane reci (za prestanak, ukucati rec kraj):\n");
    while(1)
    {
        fgets(kodna_rec, MAX_KODNA_REC, stdin);
        int duzina = strlen(kodna_rec);
        if(kodna_rec[duzina - 1] == '\n')
        {
            kodna_rec[--duzina] = '\0';
        }

        if(strcmp(kodna_rec, "kraj") == 0)
        {
            break;
        }

        dekodiraj_rec(kodovi, n, kodna_rec, duzina, rec);
        fprintf(izlazna, "%s -> %s\n", kodna_rec, rec);
    }
    fclose(izlazna);

    return 0;
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

void ucitaj_kodove(FILE *ulazna, MORZEOV_KOD *kodovi, int *pn)
{
    int i = 0;

    while(fscanf(ulazna, "%c %s\n", 
            &kodovi[i].slovo, kodovi[i].kod) != EOF)
    {
        i++;
    }

    *pn = i;
}

void dekodiraj_rec(MORZEOV_KOD *kodovi, int n, char *kodna_rec, int duzina_kodne_reci, char *rec)
{
    int i, j, duzina_reci = 0, duzina_kodiranog_slova = 0, nadjen_kod = 0;
    char kodirano_slovo[MAX_KOD] = "";

    for(i = 0;i < duzina_kodne_reci;i++)
    {
        if(kodna_rec[i] == ' ' || i == duzina_kodne_reci - 1)
        {
            if(i == duzina_kodne_reci - 1)
            {
                kodirano_slovo[duzina_kodiranog_slova++] = kodna_rec[i];
            }

            kodirano_slovo[duzina_kodiranog_slova++] = '\0';
            for(j = 0;j < n;j++)
            {
                if(strcmp(kodirano_slovo, kodovi[j].kod) == 0)
                {
                    rec[duzina_reci++] = kodovi[j].slovo;
                    nadjen_kod = 1;
                    break;
                }
            }

            if(!nadjen_kod)
            {
                rec[duzina_reci++] = '?';
            }

            duzina_kodiranog_slova = 0;
        }
        else
        {
            kodirano_slovo[duzina_kodiranog_slova++] = kodna_rec[i];
        }
    }

    rec[duzina_reci++] = '\0';
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAZIV_KOMPANIJE 12

#define MAX_SIZE 30

typedef struct rast_deonica_st
{
    char naziv_kompanije[MAX_NAZIV_KOMPANIJE];
    double prvi_procenat;
    double drugi_procenat;
    double treci_procenat;
    double cetvrti_procenat;
    double peti_procenat;
} RAST_DEONICA;

FILE *safe_fopen(char *ime, char *rezim, int kod_greske);
void ucitaj_rast_deonica(FILE *ulazna, RAST_DEONICA *rd, int *pn);
double sumiraj_rast_na_dnevnom_nivou(double prvi_procenat, double drugi_procenat, double treci_procenat, double cetvrti_procenat, double peti_procenat);
double izracunaj_rast(double trenutna, double rast);
int stagnira(double trenutna, double pocetna, double prag);
void ispisi_trend(FILE *izlazna, double trenutna, double pocetna, double prag, double rast);
void sumiraj_informacije_o_deonicama(FILE *izlazna, RAST_DEONICA *rd, int n, double pocetna_A, double pocetna_B, double pocetna_C, double pocetna_D, double prag);

int main(int argc, char **argv)
{
    RAST_DEONICA rast_deonica[MAX_SIZE];
    int n;

    if(argc != 8)
    {
        printf("Primer poziva: %s deonice.txt izvestaj.txt 100.0 200.0 80.0 120.0 0.002\n", argv[0]);
        exit(2);
    }

    FILE *ulazna = safe_fopen(argv[1], "r", 3);
    ucitaj_rast_deonica(ulazna, rast_deonica, &n);
    fclose(ulazna);

    double pocetna_A = atof(argv[3]);
    double pocetna_B = atof(argv[4]);
    double pocetna_C = atof(argv[5]);
    double pocetna_D = atof(argv[6]);
    double prag = atof(argv[7]);

    FILE *izlazna = safe_fopen(argv[2], "w", 4);
    sumiraj_informacije_o_deonicama(izlazna, rast_deonica, n, pocetna_A, pocetna_B, pocetna_C, pocetna_D, prag);
    fclose(izlazna);

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

void ucitaj_rast_deonica(FILE *ulazna, RAST_DEONICA *rd, int *pn)
{
    int i = 0;

    while(fscanf(ulazna, "%s %lf %lf %lf %lf %lf", 
            rd[i].naziv_kompanije, &rd[i].prvi_procenat, &rd[i].drugi_procenat, &rd[i].treci_procenat, &rd[i].cetvrti_procenat, &rd[i].peti_procenat) != EOF)
    {
        i++;
    }

    *pn = i;
}

double sumiraj_rast_na_dnevnom_nivou(double prvi_procenat, double drugi_procenat, double treci_procenat, double cetvrti_procenat, double peti_procenat)
{
    return prvi_procenat + drugi_procenat + treci_procenat + cetvrti_procenat + peti_procenat;
}

double izracunaj_rast(double trenutna, double rast)
{
    return trenutna *= (1 + rast / 100);
}

int stagnira(double trenutna, double pocetna, double prag)
{
    double opseg = prag * pocetna;
    return trenutna >= (pocetna - opseg) && trenutna <= (pocetna + opseg);
}

void ispisi_trend(FILE *izlazna, double trenutna, double pocetna, double prag, double rast)
{
    if(stagnira(trenutna, pocetna, prag))
    {
        fputs("stagnacija\n", izlazna);
        return;
    }

    if(rast < 0)
    {
        fputs("pad\n", izlazna);
    }
    else
    {
        fputs("rast\n", izlazna);
    }
}

void sumiraj_informacije_o_deonicama(FILE *izlazna, RAST_DEONICA *rd, int n, double pocetna_A, double pocetna_B, double pocetna_C, double pocetna_D, double prag)
{
    int i;
    double pocetna, trenutna, trenutna_A = pocetna_A, trenutna_B = pocetna_B, trenutna_C = pocetna_C, trenutna_D = pocetna_D;
    double rast;

    for(i = 0;i < n;i++)
    {
        rast = sumiraj_rast_na_dnevnom_nivou(rd[i].prvi_procenat, rd[i].drugi_procenat, rd[i].treci_procenat, rd[i].cetvrti_procenat, rd[i].peti_procenat);

        if(strcmp(rd[i].naziv_kompanije, "Kompanija_A") == 0)
        {
            pocetna = pocetna_A;
            trenutna_A = izracunaj_rast(trenutna_A, rast);
            trenutna = trenutna_A;
        }
        else if(strcmp(rd[i].naziv_kompanije, "Kompanija_B") == 0)
        {
            pocetna = pocetna_B;
            trenutna_B = izracunaj_rast(trenutna_B, rast);
            trenutna = trenutna_B;
        }
        else if(strcmp(rd[i].naziv_kompanije, "Kompanija_C") == 0)
        {
            pocetna = pocetna_C;
            trenutna_C = izracunaj_rast(trenutna_C, rast);
            trenutna = trenutna_C;
        }
        else if(strcmp(rd[i].naziv_kompanije, "Kompanija_D") == 0)
        {
            pocetna = pocetna_D;
            trenutna_D = izracunaj_rast(trenutna_D, rast);
            trenutna = trenutna_D;
        }
        else
        {
            printf("Ne postoji pocetna vrednost akcija za kompaniju %s!\n", rd[i].naziv_kompanije);
            continue;
        }

        fprintf(izlazna, "%s %.2lf ", rd[i].naziv_kompanije, trenutna);
        ispisi_trend(izlazna, trenutna, pocetna, prag, rast); 
    }
}

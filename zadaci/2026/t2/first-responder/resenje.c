#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_MESTO 31

#define MAX_SIZE 30

#define R 6371.0

typedef struct vatrogasci_st
{
    char mesto[MAX_MESTO];
    double geografska_sirina;
    double geografska_duzina;
} VATROGASCI;

void ucitaj_vatrogasna_drustva(VATROGASCI *v, int *pn);
double domet_kategorije(char kategorija_pozara);
double stepeni_u_radijane(double stepeni);
double haversinusna_razdaljina(double geogr_sirina1, double geogr_duzina1, double geogr_sirina2, double geogr_duzina2);
void ispisi_angazovana_vatrogasna_drustva(
    VATROGASCI *v, int n, double geografska_sirina_pozara, double geografska_duzina_pozara, double poluprecnik);

int main(int argc, char **argv)
{
    VATROGASCI vatrogasci[MAX_SIZE];
    int n;

    if(argc != 4)
    {
        printf("Primer poziva: %s 45.25388 19.85194 Z < vatrogasci.txt\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ucitaj_vatrogasna_drustva(vatrogasci, &n);

    double geografska_sirina_pozara = atof(argv[1]);
    double geografska_duzina_pozara = atof(argv[2]);
    char kategorija_pozara = argv[3][0];

    double poluprecnik = domet_kategorije(kategorija_pozara);

    printf("\n\n");
    ispisi_angazovana_vatrogasna_drustva(vatrogasci, n, geografska_sirina_pozara, geografska_duzina_pozara, poluprecnik);

    return EXIT_SUCCESS;
}

void ucitaj_vatrogasna_drustva(VATROGASCI *v, int *pn)
{
    int i;

    do
    {
        printf("Unesite broj vatrogasnih drustava: ");
        scanf("%d", pn);
    } while (*pn <= 0 || *pn > MAX_SIZE);
    
    for(i = 0;i < *pn;i++)
    {
        printf("\n%d. vatrogasno drustvo: ", i + 1);
        scanf("%s %lf %lf", v[i].mesto, &v[i].geografska_sirina, &v[i].geografska_duzina);
    }
}

double domet_kategorije(char kategorija_pozara)
{
    switch(kategorija_pozara)
    {
        case 'Z':
            return 5.0;
        case 'N':
            return 10.0;
        case 'C':
            return 20.0;
    }

    return 0.0;
}

double stepeni_u_radijane(double stepeni)
{
    return stepeni * M_PI / 180;
}

double haversinusna_razdaljina(double geogr_sirina1, double geogr_duzina1, double geogr_sirina2, double geogr_duzina2)
{
    double fi1 = stepeni_u_radijane(geogr_sirina1);
    double fi2 = stepeni_u_radijane(geogr_sirina2);

    double delta_fi = stepeni_u_radijane(geogr_sirina2 - geogr_sirina1);
    double delta_lambda = stepeni_u_radijane(geogr_duzina2 - geogr_duzina1);

    double a = pow(sin(delta_fi / 2), 2) +
               cos(fi1) * cos(fi2) *
               pow(sin(delta_lambda / 2), 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return R * c;
}

void ispisi_angazovana_vatrogasna_drustva(
    VATROGASCI *v, int n, double geografska_sirina_pozara, double geografska_duzina_pozara, double poluprecnik)
{
    int i, indeks_najblizeg = 0;
    double vazdusne_razdaljine[MAX_SIZE], najbliza_razdaljina = haversinusna_razdaljina(
            v[0].geografska_sirina, v[0].geografska_duzina, geografska_sirina_pozara, geografska_duzina_pozara);;

    for(i = 0;i < n;i++)
    {
        vazdusne_razdaljine[i] = haversinusna_razdaljina(
            v[i].geografska_sirina, v[i].geografska_duzina, geografska_sirina_pozara, geografska_duzina_pozara);
        
        if(vazdusne_razdaljine[i] < najbliza_razdaljina)
        {
            najbliza_razdaljina = vazdusne_razdaljine[i];
            indeks_najblizeg = i;
        }
    }

    int ima_u_poluprecniku = 0;

    for(i = 0;i < n;i++)
    {
        if(indeks_najblizeg == i)
        {
            strcat(v[i].mesto, "(FR)");
        }

        if(vazdusne_razdaljine[i] <= poluprecnik)
        {
            printf("%s %.2lfkm\n", v[i].mesto, vazdusne_razdaljine[i]);
            ima_u_poluprecniku = 1;
        }
    }

    if(ima_u_poluprecniku == 0)
    {
        printf("%s %.2lfkm\n", v[indeks_najblizeg].mesto, vazdusne_razdaljine[indeks_najblizeg]);
    }
}

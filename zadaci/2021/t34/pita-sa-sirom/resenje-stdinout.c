#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NIZ 30

#define MAX_SIROVINA 31

typedef struct sirovine_st {
    char naziv_sirovine[MAX_SIROVINA];
    unsigned limit_za_velikoprodaju;
    double maloprodajna_cena;
    double velikoprodajna_cena;
} SIROVINE;

void ucitaj_sirovine(SIROVINE *sirovine, int *pn);
void ispisi_cene(SIROVINE *sirovine, int n, unsigned kolicina);
double izracunaj_kolicinu_sirovine(char *naziv_sirovine, unsigned kolicina);
double izracunaj_cenu(double kolicina_sirovine, unsigned limit_za_velikoprodaju,
                      double maloprodajna_cena, double velikoprodajna_cena);

int main(int argc, char **argv) {
    SIROVINE sirovine[MAX_NIZ];
    int n;

    if(argc != 2) {
        printf("Primer poziva programa: %s 120 < sirovine-stdinout.txt\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ucitaj_sirovine(sirovine, &n);

    printf("\n\n");
    unsigned kolicina = atoi(argv[1]);
    ispisi_cene(sirovine, n, kolicina);

    return EXIT_SUCCESS;
}

void ucitaj_sirovine(SIROVINE *sirovine, int *pn) {
    int i;

    do
    {
        printf("Unesite broj sirovina: ");
        scanf("%d", pn);
    } while (*pn <= 0 || *pn > MAX_SIROVINA);

    for (i = 0; i < *pn; i++)
    {
        printf("%d. sirovina: ", i + 1);

        scanf("%s %u %lf %lf",
            sirovine[i].naziv_sirovine,
            &sirovine[i].limit_za_velikoprodaju,
            &sirovine[i].maloprodajna_cena,
            &sirovine[i].velikoprodajna_cena);
    }
}

void ispisi_cene(SIROVINE *sirovine, int n, unsigned kolicina) {
    int i;
    double kolicina_sirovine, cena_sirovine;

    for(i = 0;i < n;i++) {
        kolicina_sirovine = izracunaj_kolicinu_sirovine(
                                sirovine[i].naziv_sirovine,
                                kolicina
                            );
        cena_sirovine = izracunaj_cenu(
                            kolicina_sirovine,
                            sirovine[i].limit_za_velikoprodaju,
                            sirovine[i].maloprodajna_cena,
                            sirovine[i].velikoprodajna_cena
                        );
        printf("%6s %5.2lf %8.2lf\n", sirovine[i].naziv_sirovine, kolicina_sirovine, cena_sirovine);
    }
}

double izracunaj_kolicinu_sirovine(char *naziv_sirovine, unsigned kolicina) {
    double udeo_sirovine;

    if(strcmp(naziv_sirovine, "brasno") == 0) {
        udeo_sirovine = 0.6;
    } else if(strcmp(naziv_sirovine, "sir") == 0) {
        udeo_sirovine = 0.4;
    } else if(strcmp(naziv_sirovine, "ulje") == 0) {
        udeo_sirovine = 0.1;
    } else if(strcmp(naziv_sirovine, "so") == 0) {
        udeo_sirovine = 0.02;
    } else {
        udeo_sirovine = 0;      // Nepoznata sirovina se nece ubrajati u proracun
    }

    return udeo_sirovine * kolicina;
}

double izracunaj_cenu(double kolicina_sirovine, unsigned limit_za_velikoprodaju,
                      double maloprodajna_cena, double velikoprodajna_cena) {

    double izabrana_cena = kolicina_sirovine < limit_za_velikoprodaju ? maloprodajna_cena : velikoprodajna_cena;
    return kolicina_sirovine * izabrana_cena;
}


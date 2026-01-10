#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PICA 20
#define MAX_NAZIV 31
#define MAX_VEGE 3
#define MAX_SREDJEN_NAZIV 54


typedef struct pica_st {
    char naziv[MAX_NAZIV];
    double cena;
    int precnik;
    char vege[MAX_VEGE];
    char pun_naziv[MAX_SREDJEN_NAZIV];
} PICA;

void ucitaj_pice(PICA *, int *);
double suma_cena(PICA *, int);
double prosek_cena(PICA *, int);
void ispisi_vece(PICA *, int, double);
int sredjeni_nazivi(PICA *, int);

int main(int argc, char **argv) {

    PICA pice[MAX_PICA];
    int n, i;

    if(argc != 2) {
        printf("Primer poziva: %s 500.00\n", argv[0]);
        exit(1);
    }

    ucitaj_pice(pice, &n);
    double prosek = prosek_cena(pice, n);
    printf("Prosecna pica kosta: %.2lf dinara.\n", prosek);
    
    double trazena_povrsina = atof(argv[1]);
    ispisi_vece(pice, n, trazena_povrsina);
    
    int br_veg = sredjeni_nazivi(pice, n);
    printf("\n");
    for(i = 0; i < n; i++) {
        printf("%s\n", pice[i].pun_naziv);
    }
    printf("\nIma %d vegetarijanskih pica u ponudi.\n", br_veg);
    
    return 0;
}

void ucitaj_pice(PICA *p, int *pn) {

    int i;

    do {
        scanf("%d", pn);
    } while (*pn <= 0 || *pn > MAX_PICA);

    for (i = 0; i < *pn; i++) {
        scanf("%s %lf %d %s", p[i].naziv, &p[i].cena, &p[i].precnik, p[i].vege);
    }
}

double suma_cena(PICA *p, int n) {
    int i;
    double suma = 0;
    
    for(i = 0; i < n; i++) {
        suma += p[i].cena;
    }
    
    return suma;
}

double prosek_cena(PICA *p, int n) {
    return suma_cena(p, n) / n;
}

void ispisi_vece(PICA *p, int n, double povrsina) {
    int i;
    int nadjena = 0;
    printf("Pice koje su vece od unete povrsine: ");
    for(i = 0; i < n; i++) {
        float temp = p[i].precnik * p[i].precnik * 3.14 / 4;
        if(temp > povrsina) {
            printf("%s ", p[i].naziv);
            nadjena = 1;
        }
    }
    printf("\n");
    
    if (nadjena == 0) {
        printf("Nije pronadjena pica veca od unete povrsine!\n");
        exit(2);
    }
}

int sredjeni_nazivi(PICA *p, int n) {
    int i, j, br_veg = 0;
    for(i = 0; i < n; i++) {
        char naziv[MAX_SREDJEN_NAZIV];
        strcpy(naziv, p[i].naziv);
        if (p[i].precnik < 25) {
            strcat(naziv, " mala");
        } else if (p[i].precnik <= 40) {
            strcat(naziv, " srednja");
        } else {
            strcat(naziv, " velika");
        }
        
        if (strcmp(p[i].vege, "da") == 0) {
            strcat(naziv, " vegetarijanska");
            br_veg++;
        }
        strcpy(p[i].pun_naziv, naziv);
    }
    
    return br_veg;
}

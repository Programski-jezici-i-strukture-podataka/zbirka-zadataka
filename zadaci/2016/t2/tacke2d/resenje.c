#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 30
#define MAX_NAZIV 41

typedef struct tacka_st {
    double x;
    double y;
} TACKA;

FILE *safe_fopen(char *, char *, int);
void ucitaj_tacke(FILE *, TACKA *, int *);
void ispisi_tacke(FILE *, TACKA *, int);
void ispisi_tacku(FILE *, TACKA);

unsigned prebroj_trouglove(TACKA *, int);
TACKA pronadji_teziste(TACKA *, int);
void pripada_krugu(TACKA *, TACKA *, 
                   int, int *, TACKA, double);

int obrazuju_trougao(TACKA, TACKA, TACKA);
double udaljenost(TACKA, TACKA);

int main(int argc, char **argv) {
    TACKA tacke[MAX_SIZE], pripadaju_krugu[MAX_SIZE];
    int n, m;

    if(argc != 3) {
        printf("Niste dobro pozvali program. Primer poziva: %s tacke.txt 5\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *pin = safe_fopen(argv[1], "r", EXIT_FAILURE);
    ucitaj_tacke(pin, tacke, &n);
    fclose(pin);

    // a)

    char naziv[MAX_NAZIV];
    strcpy(naziv, "pripada_krugu_poluprecnika_");
    strcat(naziv, argv[2]);
    strcat(naziv, ".txt");

    double r = atof(argv[2]);
    TACKA teziste = pronadji_teziste(tacke, n);

    FILE *pout = safe_fopen(naziv, "w", EXIT_FAILURE);
    fprintf(pout, "Krug poluprecnika %.2lf sa centrom u tacki ", r);
    ispisi_tacku(pout, teziste);
    fprintf(pout, "\n");

    // b)

    pripada_krugu(pripadaju_krugu, tacke, n, &m, teziste, r);
    ispisi_tacke(pout, pripadaju_krugu, m);

    fclose(pout);

    // c)

    pout = safe_fopen("trouglovi.txt", "w", EXIT_FAILURE);
    fprintf(pout, "Broj trouglova: %u\n", prebroj_trouglove(tacke, n));

    fclose(pout);

    return EXIT_SUCCESS;
}

FILE *safe_fopen(char *pname, char *pmode, int error_code) {
    FILE *pf = fopen(pname, pmode);

    if(pf == NULL) {
        printf("Datoteka sa imenom %s nije uspesno otvorena.\n", pname);
        exit(error_code);
    }

    return pf;
}

void ucitaj_tacke(FILE *pin, TACKA *tacke, int *pn) {
    int i = 0;

    while(fscanf(pin, "%lf %lf", &tacke[i].x,
                                 &tacke[i].y) != EOF) {
        i++;
    }

    *pn = i;
}

void ispisi_tacke(FILE *pout, TACKA *tacke, int n) {
    int i;

    for(i = 0;i < n;i++) {
        ispisi_tacku(pout, tacke[i]); 
    }
}

void ispisi_tacku(FILE *pout, TACKA tacka) {
    fprintf(pout, "(%.2lf, %.2lf)\n", tacka.x, tacka.y);
}

unsigned prebroj_trouglove(TACKA *tacke, int n) {
    int i, j, k;
    unsigned broj_trouglova = 0;

    for(i = 0;i < n;i++) {
        for(j = i + 1;j < n;j++) {
            for(k = j + 1;k < n;k++) {
                if(obrazuju_trougao(tacke[i],
                                    tacke[j],
                                    tacke[k])) {
                    broj_trouglova++;
                }            
            }
        }
    }

    return broj_trouglova;
}

TACKA pronadji_teziste(TACKA *tacke, int n) {
    int i;
    double suma_x = 0, suma_y = 0;

    TACKA tezisna_tacka;

    for(i = 0;i < n;i++) {
        suma_x += tacke[i].x;
        suma_y += tacke[i].y;
    }

    tezisna_tacka.x = suma_x / n;
    tezisna_tacka.y = suma_y / n;

    return tezisna_tacka;
}

void pripada_krugu(TACKA *pripada, TACKA *tacke, 
                   int n, int *pm, TACKA centar, double r) {
    int i, j = 0;

    for(i = 0;i < n;i++) {
        if(udaljenost(tacke[i], centar) <= r) {
            pripada[j] = tacke[i];
            j++;
        }
    }

    *pm = j;
}

int obrazuju_trougao(TACKA t1, TACKA t2, TACKA t3) {
    double a = udaljenost(t1, t2);
    double b = udaljenost(t2, t3);
    double c = udaljenost(t1, t3);

    return (a + b > c) && (b + c > a) && (c + a > b);
}

double udaljenost(TACKA t1, TACKA t2) {
    return sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2));
}


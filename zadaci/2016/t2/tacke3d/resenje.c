#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 30
#define MAX_NAZIV 42

typedef struct tacka_st {
    double x;
    double y;
    double z;
    double udaljenost_od_pocetka;
} TACKA;

FILE *safe_fopen(char *, char *, int);
void ucitaj_tacke(FILE *, TACKA *, int *);
void ispisi_tacke(FILE *, TACKA *, int);
void ispisi_tacku(FILE *, TACKA);

TACKA najbliza_pocetku(TACKA *, int);
TACKA najdalja_od_pocetka(TACKA *, int);

double udaljenost(TACKA, TACKA);
double udaljenost_od_pocetka(TACKA);
double zapremina_kocke(double);

int main(int args_num, char **args) {
    TACKA tacke[MAX_SIZE], pripadaju_krugu[MAX_SIZE];
    int n, m;

    if(args_num != 4) {
        printf("Niste dobro pozvali program. Primer poziva: ./a.out tacke.txt tacke_formatirano.txt 5");
        exit(EXIT_FAILURE);
    }

    FILE *pin = safe_fopen(args[1], "r", EXIT_FAILURE);
    ucitaj_tacke(pin, tacke, &n);
    fclose(pin);

    // a)
    
    FILE *pout = safe_fopen(args[2], "w", EXIT_FAILURE);
    ispisi_tacke(pout, tacke, n);
    fclose(pout);
    
    // b)
    
    double zapremina_koord_kocke = zapremina_kocke(udaljenost(najbliza_pocetku(tacke, n),
                                                              najdalja_od_pocetka(tacke, n)));
    
    // c)
    
    double zapremina_arg_kocke = zapremina_kocke(atof(args[3]));
    char naziv[MAX_NAZIV];
               
    if(zapremina_koord_kocke > zapremina_arg_kocke) {
        strcpy(naziv, "sracunata_kocka_minus_argument_kocka.txt");
    } else {
        strcpy(naziv, "argument_kocka_minus_sracunata_kocka.txt");
    }
    
    pout = safe_fopen(naziv, "w", EXIT_FAILURE);
    fprintf(pout, "Zapremina sracunate kocke: %.2lf\n", zapremina_koord_kocke);
    fprintf(pout, "Zapremina argument kocke: %.2lf\n", zapremina_arg_kocke);
    fprintf(pout, "Razlika u zapreminama: %.2lf\n", fabs(zapremina_arg_kocke - zapremina_koord_kocke));
    
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

    while(fscanf(pin, "%lf %lf %lf", &tacke[i].x,
                                     &tacke[i].y,
                                     &tacke[i].z) != EOF) {
        tacke[i].udaljenost_od_pocetka = udaljenost_od_pocetka(tacke[i]);
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
    fprintf(pout, "(%.2lf, %.2lf, %.2lf), %.2lf\n", tacka.x, tacka.y, tacka.z, tacka.udaljenost_od_pocetka);
}

TACKA najbliza_pocetku(TACKA *tacke, int n) {
    int i;
    TACKA najbliza_tacka = tacke[0];
    double min_udaljenost = udaljenost_od_pocetka(najbliza_tacka);
    
    for(i = 1;i < n;i++) {
        if(udaljenost_od_pocetka(tacke[i]) < min_udaljenost) {
            min_udaljenost = udaljenost_od_pocetka(tacke[i]);
            najbliza_tacka = tacke[i];
        }
    }
    
    return najbliza_tacka;
}

TACKA najdalja_od_pocetka(TACKA *tacke, int n) {
    int i;
    TACKA najdalja_tacka = tacke[0];
    double max_udaljenost = udaljenost_od_pocetka(najdalja_tacka);
    
    for(i = 1;i < n;i++) {
        if(udaljenost_od_pocetka(tacke[i]) > max_udaljenost) {
            max_udaljenost = udaljenost_od_pocetka(tacke[i]);
            najdalja_tacka = tacke[i];
        }
    }
    
    return najdalja_tacka;
}

double udaljenost(TACKA t1, TACKA t2) {
    return sqrt(pow(t1.x - t2.x, 2) + pow(t1.y - t2.y, 2) + pow(t1.z - t2.z, 2));
}

double udaljenost_od_pocetka(TACKA t) {
    return sqrt(pow(t.x, 2) + pow(t.y, 2) + pow(t.z, 2));
}

double zapremina_kocke(double a) {
    return pow(a, 3);
}


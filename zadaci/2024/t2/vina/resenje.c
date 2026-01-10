#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VINA 20
#define MAX_NAZIV 31
#define MAX_TIP 11

typedef struct vino_st {
    char naziv[MAX_NAZIV];
    int osnovna_cena;
    double kolicina;
    int godiste;
    char tip[MAX_TIP];
} VINO;

void ucitaj_vina(VINO *, int *);
void izmena_naziva(VINO *, int);
void ispis_po_tipu(VINO *v, int n, char *tip);
void nadji_cene(VINO *v, int n);

int main(int argc, char **argv) {

    VINO vina[MAX_VINA];
    int n;

    if(argc != 2) {
        printf("Primer poziva: %s belo\n", argv[0]);
        exit(1);
    }
    
    ucitaj_vina(vina, &n);
    izmena_naziva(vina, n);
    ispis_po_tipu(vina, n, argv[1]);
    nadji_cene(vina, n);

    return 0;
}

void ucitaj_vina(VINO *v, int *pn) {

    int i;

    do {
        scanf("%d", pn);
    } while (*pn <= 0 || *pn > MAX_VINA);

    for (i = 0; i < *pn; i++) {
        scanf("%s %d %lf %d %s", v[i].naziv, &v[i].osnovna_cena, &v[i].kolicina, &v[i].godiste, v[i].tip);
    }
}

void izmena_naziva(VINO *v, int n) {
    int i, j;
    
    for(i = 0; i < n; i++) {   
        int prvo_slovo = 1;
        for(j = 0; j < strlen(v[i].naziv); j++) {
            if ((v[i].naziv[j] >= 'A') && (v[i].naziv[j] <= 'Z') && (prvo_slovo == 0)) {
                v[i].naziv[j] += 32;
            } else if ((v[i].naziv[j] >= 'a') && (v[i].naziv[j]) <= 'z' && (prvo_slovo == 1)) {
                v[i].naziv[j] -= 32;
            }
        
            prvo_slovo = 0;
            if (v[i].naziv[j] == '_') {
                v[i].naziv[j] = ' ';
                prvo_slovo = 1;
            }
        }
    }
}

void ispis_po_tipu(VINO *v, int n, char *tip) {
    int i, nadjeno = 0;
    printf("Vina datog tipa:\n");
    for(i = 0; i < n; i++) {
        if (strcmp(v[i].tip, tip) == 0) {
            printf("%s\n", v[i].naziv);
            nadjeno = 1;
        }
    }
    printf("\n");
    if (!nadjeno) {
        printf("Nije nadjeno vino datog tipa.\n");
        exit(2);
    }
}

void nadji_cene(VINO *v, int n) {
   int i;
   for(i = 0; i < n; i++) {
      double tip = 0;
      if (strcmp(v[i].tip, "belo") == 0) {
          tip = 1.33;
      } else if (strcmp(v[i].tip, "roze") == 0) {
          tip = 1;
      } else if (strcmp(v[i].tip, "crveno") == 0) {
          tip = 0.66;
      } else {
          printf("Tip vina %s je neispravan: %s\n", v[i].naziv, v[i].tip);
          exit(3);
      }
          
      double cena = (v[i].osnovna_cena + (2024 - v[i].godiste) * 100) * v[i].kolicina / tip;
      printf("%s %.2lf\n", v[i].naziv, cena);
   }
   
}

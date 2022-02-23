#include <stdio.h>
// Na novijim verzijama kompajlera, funkcija __fpurge se nalazi u biblioteci stdio_ext.h
// Po potrebi, odkomentarisati narednu liniju
// #include <stdio_ext.h>
#include <string.h>

#define MAX 30
#define MAX_S 8

int main () {
    float struja[MAX];
    char tarifa[MAX_S];
    int i, n;
    float cena;
    int c = 0, z = 0, p = 0;

    do {
        printf("Unesite broj domacinstava za koji zelite da izracunate cenu struje: ");
        scanf("%d", &n);
    }
    while(n <= 0 || n > MAX);

    do {
    printf("Unesite tarifu: ");
    __fpurge(stdin);
    scanf("%s", tarifa);
    }
    while(!(strcmp(tarifa, "osnovna")==0 || strcmp(tarifa, "niza")==0 || strcmp(tarifa, "visa")==0));


    for(i = 0; i < n; i++) {
        printf("Potrosnja %d. domacinstva: ", i+1);
        scanf("%f", &struja[i]);
    }

    for(i = 0; i < n; i++) {

        if(struja[i] <= 350) {
            z++;
            if(strcmp(tarifa, "osnovna") == 0) {
              cena = 5.108 * struja[i];
            }
            else if(strcmp(tarifa, "niza") == 0) {
              cena = 1.491 * struja[i];
            }
            else {
              cena = 5.962 * struja[i];
            }

        }
        else if(struja[i] > 350 && struja[i] <= 1600) {
            p++;
            if(strcmp(tarifa, "osnovna") == 0) {
              cena = 7.658 * struja[i];
            }
            else if(strcmp(tarifa, "niza") == 0) {
              cena = 2.236 * struja[i];
            }
            else {
              cena = 8.943 * struja[i];
            }

        }
        else if(struja[i] > 1600) {
            c++;
            if(strcmp(tarifa, "osnovna") == 0) {
              cena = 15.330 * struja[i];
            }
            else if(strcmp(tarifa, "niza") == 0) {
              cena = 4.647 * struja[i];
            }
            else {
              cena = 18.588 * struja[i];
            }
        }

        printf("Cena struje %d. domacinstva je %.2f dinara.\n", i+1, cena);
    }

    printf("Broj domacinstava u zelenoj zoni je %d.\n", z);
    printf("Broj domacinstava u plavoj zoni je %d.\n", p);
    printf("Broj domacinstava u crvenoj zoni je %d.\n", c);


    return 0;
}

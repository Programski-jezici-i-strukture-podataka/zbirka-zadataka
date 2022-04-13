#include <stdio.h>
#include <math.h>

#define MAX_SIZE 20

int main() {
    double R[MAX_SIZE];
    int i, n;

    do {
        printf("Unesite broj clanova niza: ");
        scanf("%d", &n);
    } while(n <= 0 || n > MAX_SIZE);

    for(i = 0;i < n;i++) {
        do {
            printf("R[%d] = ", i);
            scanf("%lf", &R[i]);
        } while(R[i] <= 0);
    }

    double U;

    printf("Unesite jacinu napona u voltima: ");
    scanf("%lf", &U);
    printf("\n");

    double ukupna_otpornost, ukupna_provodnost = 0, ukupna_struja;

    for(i = 0;i < n;i++) {
        ukupna_provodnost += 1 / R[i];
    }
    ukupna_otpornost = 1 / ukupna_provodnost;

    ukupna_struja = U / ukupna_otpornost;
    printf("Ukupna struja: %.2lfA\n", ukupna_struja);

    double  otpornost_ostalih, provodnost_ostalih = 0, struja_prvog, procenat;

    for(i = 1;i < n;i++) {
        provodnost_ostalih += 1 / R[i];
    }
    otpornost_ostalih = 1 / provodnost_ostalih;

    struja_prvog = otpornost_ostalih / (otpornost_ostalih + R[0]) * ukupna_struja;
    procenat = struja_prvog / ukupna_struja * 100;

    printf("Procentualni udeo struje: %.2lf%%\n", procenat);

    double P[MAX_SIZE];

    for(i = 0;i < n;i++) {
        P[i] = pow(U, 2) / R[i];
    }

    printf("[");
    for(i = 0;i < n;i++) {
        if(i > 0) {
            printf(", ");
        }
        printf("%.2lfW", P[i]);
    }
    printf("]\n");

    return 0;
}


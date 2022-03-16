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
        } while(R <= 0);
    }

    double I;

    printf("Unesite jacinu struje u amperima: ");
    scanf("%lf", &I);
    printf("\n");

    double ukupna_otpornost = 0, ukupan_napon;

    for(i = 0;i < n;i++) {
        ukupna_otpornost += R[i];
    }

    ukupan_napon = ukupna_otpornost * I;
    printf("Ukupan napon: %.2lfV\n", ukupan_napon);

    double max = R[0], max_napon, procenat;

    for(i = 1;i < n;i++) {
        if(max < R[i]) {
            max = R[i];
        }
    }

    max_napon = max * I;
    procenat = max_napon / ukupan_napon * 100;

    printf("Procentualni udeo napona: %.2lf%%\n", procenat);

    double P[MAX_SIZE];

    for(i = 0;i < n;i++) {
        P[i] = R[i] * pow(I, 2);
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


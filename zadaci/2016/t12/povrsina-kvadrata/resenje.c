#include <stdio.h>

#define MAX_SIZE 30

int main() {
    double a[MAX_SIZE];
    int i, n;

    do {
        printf("Unesite broj elemenata niza: ");
        scanf("%d", &n);
    } while(n <= 0 || n > MAX_SIZE);

    for(i = 0;i < n;i++) {
        printf("a[%d] = ", i);
        scanf("%lf", &a[i]);
    }

    printf("\n");

    double suma = 0, srednja_vrednost;

    for(i = 0;i < n;i++) {
        suma += a[i];
    }

    srednja_vrednost = suma / n;
    printf("Prosecna duzina duzi: %.2lf\n", srednja_vrednost);

    double P[MAX_SIZE];

    for(i = 0;i < n;i++) {
        P[i] = a[i] * a[i];
    }

    printf("[");
    for(i = 0;i < n;i++) {
        if(i > 0) {
            printf(", ");
        }
        printf("%.2lf", P[i]);
    }
    printf("]\n");

    double max_P = P[0], suma_P = 0, procenat_P;

    for(i = 1;i < n;i++) {
        if(P[i] > max_P) {
            max_P = P[i];
        }
    }

    for(i = 0;i < n;i++) {
        if(suma_P + P[i] < max_P) {
            suma_P += P[i];
        }
    }

    procenat_P = suma_P / max_P * 100;
    printf("Procenat zauzeca povrsine najveceg kvadrata: %.2lf%%\n", procenat_P);

    return 0;
}


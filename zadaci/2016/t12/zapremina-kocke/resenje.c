#include <stdio.h>
#include <math.h>

#define MAX_SIZE 30

int main() {
    double a[MAX_SIZE];
    int i, n;

    do {
        printf("Unesite broj clanova niza: ");
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

    double V[MAX_SIZE];

    for(i = 0;i < n;i++) {
        V[i] = pow(a[i], 3);
    }

    printf("[");
    for(i = 0;i < n;i++) {
        if(i > 0) {
            printf(", ");
        }
        printf("%.2lf", V[i]);
    }
    printf("]\n");

    double srednja_V = pow(srednja_vrednost, 3);
    double najbliza_V = V[0], min_razlika = fabs(V[0] - srednja_V);

    for(i = 1;i < n;i++) {
        if(fabs(V[i] - srednja_V) < min_razlika) {
            min_razlika = fabs(V[i] - srednja_V);
            najbliza_V = V[i];
        }
    }

    printf("Zapremina najbliza srednjoj je: %.2lf\n", najbliza_V);

    return 0;
}

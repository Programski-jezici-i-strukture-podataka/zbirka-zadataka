#include <stdio.h>
#include <math.h>

#define MAX_NIZ 30

int main() {
    double x[MAX_NIZ], y[MAX_NIZ];
    int i, n;

    do {
        printf("Ucitati zeljeni broj koordinata: ");
        scanf("%d", &n);
    } while(n <= 0 || n > MAX_NIZ);

    for(i = 0;i < n;i++) {
        printf("%d. tacka\n", i + 1);
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
        printf("\n");
    }

    printf("[");
    for(i = 0;i < n;i++) {
        if(i > 0) {
            printf(", ");
        }
        printf("(%.2lf, %.2lf)", x[i], y[i]);
    }
    printf("]\n");

    double predjeno = 0;

    for(i = 1;i < n;i++) {
        predjeno += sqrt(pow(x[i - 1] - x[i], 2) + pow(y[i - 1] - y[i], 2));
    }

    printf("Ukupno predjena distanca glave masine: %.2lf\n", predjeno);

    return 0;
}


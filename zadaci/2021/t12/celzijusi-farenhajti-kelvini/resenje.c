#include <stdio.h>
#include <string.h>

#define MAX_NIZ 30

int main() {
    double tempc[MAX_NIZ], tempf[MAX_NIZ], tempk[MAX_NIZ];
    double sumac = 0, sumaf = 0, sumak = 0;
    double srvrc, srvrf, srvrk;
    int i, n;

    do {
        printf("Unesite broj elemenata: ");
        scanf("%d", &n);
    } while(n <= 0 || n > MAX_NIZ);

    for(i = 0;i < n;i++) {
        printf("tempc[%d] = ", i);
        scanf("%lf", &tempc[i]);
    }

    for(i = 0;i < n;i++) {
        tempf[i] = (tempc[i] * 1.8) + 32;
        tempk[i] = tempc[i] + 273.15;
    }

    for(i = 0;i < n;i++) {
        sumac += tempc[i];
        sumaf += tempf[i];
        sumak += tempk[i];
    }

    srvrc = sumac / n;
    srvrf = sumaf / n;
    srvrk = sumak / n;

    printf("\nT[C]  T[F]  T[K]\n");
    printf("------------------\n");

    for(i = 0;i < n;i++) {
        printf("%5.1lf %5.1lf %5.1lf\n", tempc[i], tempf[i], tempk[i]);
    }

    printf("------------------\n");
    printf("%5.1lf %5.1lf %5.1lf\n", srvrc, srvrf, srvrk);

    return 0;
}


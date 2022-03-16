#include <stdio.h>
#include <math.h>

#define MAX_SIZE 30

int main() {
    double h[MAX_SIZE], m, g = 9.81;
    int i, n;

    do {
        printf("Unesite broj visina: ");
        scanf("%d", &n);
    } while(n <= 0 || n > MAX_SIZE);

    printf("Unesite visine [m]:\n");
    for(i = 0;i < n;i++) {
        do {
            printf("h[%d] = ", i);
            scanf("%lf", &h[i]);
        } while(h < 0);
    }

    do {
        printf("Unesite masu tela [kg]: ");
        scanf("%lf", &m);
    } while(m <= 0);

    printf("\n");

    double E_ukupno, max_h = h[0];

    for(i = 1;i < n;i++) {
        if(max_h < h[i]) {
            max_h = h[i];
        }
    }

    E_ukupno = m * g * max_h;
    printf("Ukupna energija: %.2lfJ\n", E_ukupno);


    double delta_E = E_ukupno;
    double E_trenutno;
    
    for(i = 0;i < n;i++) {
        E_trenutno = fabs(E_ukupno - 2 * (m * g * h[i]));
        if(delta_E > E_trenutno) {
            delta_E = E_trenutno;
        }
    }

    printf("Najmanja razlika u energijama: %.2lfJ\n", delta_E);

    double v[MAX_SIZE];
    double E_pot;

    for(i = 0;i < n;i++) {
        E_pot = m * g * h[i];
        v[i] = sqrt(2 * (E_ukupno - E_pot) / m);
    }

    printf("[");
    for(i = 0;i < n;i++) {
        if(i > 0) {
            printf(", ");
        }
        printf("%.2lfm/s", v[i]);
    }
    printf("]\n");

    return 0;
}


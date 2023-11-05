#include <stdio.h>

#define MAX_SIZE 30

int main() {
    int niz[MAX_SIZE], i, n, granica, porez;

    do {
        printf("Unesite broj artikala:");
        scanf("%d", &n);
    } while (n < 0 || n > MAX_SIZE);

    printf("Unesite cenu svakog artikla:\n");
    for(i=0;i<n;i++) {
        printf("artikal[%d]=", i);
        scanf("%d", &niz[i]);
    }

    do {
        printf("Unesite granicu za oporezivanje:");
        scanf("%d", &granica);
    } while (granica <= 0);
    
    do {
        printf("Unesite visinu poreza:");
        scanf("%d", &porez);
    } while (porez <= 0);

    double cenaSaPorezom = 1.0 + porez/100.0;

    float oporezovani[MAX_SIZE];

    int cenaPrePoreza = 0;

    float cenaPoslePoreza = 0.0;

    for(i=0;i<n;i++) {
        if(niz[i] >= granica) {
            oporezovani[i] = niz[i] * cenaSaPorezom;
        } else {
            oporezovani[i] = niz[i];
        }
        cenaPrePoreza += niz[i];
        cenaPoslePoreza += oporezovani[i];
    }

    printf("\nCene posle poreza su: \n");
    for(i=0;i<n;i++) {
        printf("artikal[%d] = %.2f\n", i, oporezovani[i]);
    }

    printf("\nUkupan racun pre poreza je %d.\n", cenaPrePoreza);
    printf("\nUkupan racun posle poreza je %.2f.\n", cenaPoslePoreza);

    return 0;
}

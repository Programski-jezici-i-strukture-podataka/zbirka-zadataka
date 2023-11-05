#include <stdio.h>
#include <string.h>

#define MAX_KUPAC 31
#define MAX_SIFRA 9

int main() {
    char kupac[MAX_KUPAC], sifra[MAX_SIFRA];
    int i, broj_artikala;
    double cena_artikla, ukupno = 0.0;

    printf("Unesite ime i prezime kupca: ");
    fgets(kupac, MAX_KUPAC, stdin);
    kupac[strlen(kupac) - 1] = '\0';

    do {
        printf("Unesite broj kupljenih artikala: ");
        scanf("%d", &broj_artikala);
    } while(broj_artikala <= 0);

    for(i = 1;i <= broj_artikala;i++) {
        printf("Sifra artikla %d: ", i);
        scanf("%s", sifra);

        do {
            printf("Cena artikla %d: ", i);
            scanf("%lf", &cena_artikla);
        } while(cena_artikla <= 0);

        if(sifra[0] == 'P') {
            cena_artikla -= cena_artikla * 0.1;
            printf("Ostvaren popust na artikal, cena %s: %.2lf\n", sifra, cena_artikla);
        }

        ukupno += cena_artikla;
    }

    printf("\nUkupno: %.2lf\n", ukupno);
    printf("Ukupno (sa PDV-om): %.2lf\n", ukupno * 1.20);

    return 0;
}

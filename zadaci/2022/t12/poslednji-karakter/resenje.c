#include <stdio.h>
#include <string.h>

#define DUZINA 100 + 1

int main() {
    char polazni[DUZINA], krajnji[DUZINA], k;
    int brojac = 0, broj_reci = 0, i, ki = 0;

    printf("Unesite polazni string: ");
    fgets(polazni, DUZINA, stdin);

    int duzina_polazni = strlen(polazni);
    if(duzina_polazni < DUZINA - 1) polazni[strlen(polazni) - 1] = '\0';

    printf("Unesite karakter: ");
    scanf("%c", &k);

    for (i = 0; i < strlen(polazni); i++) {
        if ((polazni[i] >= 'A' && polazni[i] <= 'Z') || polazni[i] == ' ' || (polazni[i] >= 'a' && polazni[i] <= 'z')) {
            krajnji[ki] = polazni[i];
            ki++;
        }
    }

    krajnji[ki] = '\0';

    int poslednja_rec;
    for (i = 0; i < strlen(krajnji); i++) {
        if (krajnji[i] == ' ') {
            broj_reci++;
            poslednja_rec = i;
            if (krajnji[i - 1] == k)
            {
                brojac++;
            }
        }
    }

    if (krajnji[strlen(krajnji) - 1] == k) {
        broj_reci++;
        brojac++;
    } else {
        broj_reci++;
    }

    printf("\nUdeo reci u polaznom stringu koji se zavrsavaju karakterom '%c' je %.2f%%.", k, ((float)brojac / broj_reci) * 100);

    for (i = 0; i < strlen(krajnji); i++) {
        if (i % 2 == 0 && krajnji[i] >= 'a' && krajnji[i] <= 'z')
            krajnji[i] = krajnji[i] - 32;
    }

    printf("\nString nakon modifikacije: %s\n", krajnji);

    return 0;
}

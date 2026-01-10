#include <stdio.h>
#include <string.h>

#define DUZINA_STRINGA 70 + 1
#define DUZINA_PODSTRINGA 20 + 1

int main() {
    char polazni[DUZINA_STRINGA], umetnuti[DUZINA_PODSTRINGA], krajnji[DUZINA_STRINGA + DUZINA_PODSTRINGA];
    int pozicija, i, j, k = 0;

    printf("Unesite polazni string: ");
    fgets(polazni, DUZINA_STRINGA, stdin);

    int duzina_polazni = strlen(polazni);
    if(duzina_polazni < DUZINA_STRINGA - 1) polazni[strlen(polazni) - 1] = '\0';

    printf("Unesite podstring koji zelite da umetnete u polazni string: ");
    fgets(umetnuti, DUZINA_PODSTRINGA, stdin);

    int duzina_umetnuti = strlen(umetnuti);
    if(duzina_umetnuti < DUZINA_PODSTRINGA - 1) umetnuti[strlen(umetnuti) - 1] = '\0';

    do {
        printf("Na koju poziciju zelite da umetnete uneti podstring (prirodan broj ne veci od %d)? ", DUZINA_STRINGA - 1);
        scanf("%d", &pozicija);
    } while (pozicija <= 0 || pozicija > DUZINA_STRINGA);

    if (strlen(polazni) < pozicija) {
        printf("\nNije moguce umetnuti string na %d. poziciju u polaznom stringu!\n", pozicija);
    } else {

        for (i = 0; i <= pozicija; i++)
            krajnji[k++] = polazni[i];

        j = i;

        for (i = 0; i < strlen(umetnuti); i++)
            krajnji[k++] = umetnuti[i];

        krajnji[k++] = ' ';

        for (i = j; i <= strlen(polazni); i++)
            krajnji[k++] = polazni[i];

        krajnji[k] = '\0';

        printf("\nString nakon modifikacije: ");

        for (i = strlen(krajnji); i >= 0; i--)
            printf("%c", krajnji[i]);

        printf("\n");
    }

    return 0;
}

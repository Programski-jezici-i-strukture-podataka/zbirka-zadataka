#include <stdio.h>
#include <string.h>

#define MAX_STR_OCENE 31
#define MAX_STR_DESK_OCENA 11
#define MAX_OCENE 10

int main() {
    char ocene_str[MAX_STR_OCENE];
    int ocene[MAX_OCENE], i, n = 0, validan_unos = 1;

    printf("Upisati ocene ucenika: ");
    fgets(ocene_str, MAX_STR_OCENE, stdin);
    int duzina_ocene_str = strlen(ocene_str);
    if(duzina_ocene_str < MAX_STR_OCENE - 1) ocene_str[duzina_ocene_str - 1] = '\0';

    for(i = 0;i < strlen(ocene_str);i++) {
        if(ocene_str[i] == ',' || ocene_str[i] == ' ') {
            continue;
        } else if(ocene_str[i] >= '1' && ocene_str[i] <= '5') {
            ocene[n] = ocene_str[i] - '0';

            if(n == MAX_OCENE) {
                printf("Moguce je uneti maksimalno %d ocena!\n", MAX_OCENE);
                validan_unos = 0;
                break;
            }

            n++;
        } else {
            printf("Karakter '%c' u unosu nije validan!\n", ocene_str[i]);
            validan_unos = 0;
            break;
        }
    }

    if(validan_unos) {
        printf("Ocene ucenika: ");
        for(i = 0;i < n;i++) {
            if(i > 0) {
                printf(", ");
            }
            printf("%d", ocene[i]);
        }
        printf("\n");

        int suma_ocena = 0;
        for(i = 0;i < n;i++) {
            suma_ocena += ocene[i];
        }

        double prosek = n != 0 ? (double)suma_ocena / n : 0;
        char deskriptivna_ocena[MAX_STR_DESK_OCENA];

        if(prosek >= 4.50 && prosek <= 5.00) {
            strcpy(deskriptivna_ocena, "odlican");
        } else if(prosek >= 3.50 && prosek < 4.50) {
            strcpy(deskriptivna_ocena, "vrlo dobar");
        } else if(prosek >= 2.50 && prosek < 3.50) {
            strcpy(deskriptivna_ocena, "dobar");
        } else if(prosek >= 1.50 && prosek < 2.50) {
            strcpy(deskriptivna_ocena, "dovoljan");
        } else {
            strcpy(deskriptivna_ocena, "nedovoljan");
        }

        printf("Prosek ucenika: %.2lf %s\n", prosek, deskriptivna_ocena);
    }

    return 0;
}


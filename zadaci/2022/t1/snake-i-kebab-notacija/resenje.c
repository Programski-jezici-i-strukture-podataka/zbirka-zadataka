#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define MAX_STR 31

int main() {
    char str[MAX_STR], notacija;

    printf("Uneti string: ");
    
    fgets(str, MAX_STR, stdin);
    int duzina_str = strlen(str);
    if (str[duzina_str - 1] == '\n') {
        str[duzina_str - 1] = '\0';
    }

    __fpurge(stdin);    // ukoliko se prekoraci broj slova koje str moze da primi, ostatak ostaje u stdin

    do {
        printf("Izaberite notaciju (moguce vrednosti - i _): ");
        scanf("%c", &notacija);
        __fpurge(stdin);
    } while(notacija != '-' && notacija != '_');

    char *s = str;
    int broj_zamenjenih = 0, greska = 0;

    while(*s != '\0') {
        if(*s >= 'A' && *s <= 'Z') {
            *s += 32;
            broj_zamenjenih++;
        } else if(*s == ' ') {
            *s = notacija;
            broj_zamenjenih++;
        } else if((*s < 'a' || *s > 'z') && (*s < '0' || *s > '9')) {
            greska = 1;
            break;
        }

        s++;
    }

    if(greska) {
        puts("\nGreska prilikom konverzije stringa u zadatu notaciju!");
    } else {
        printf("\nString nakon konverzije: %s\n", str);
        printf("Broj zamenjenih karaktera: %d\n", broj_zamenjenih);
    }

    return 0;
}

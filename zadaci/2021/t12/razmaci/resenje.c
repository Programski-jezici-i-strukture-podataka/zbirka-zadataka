#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100 


int main()
{
    char str[MAX_SIZE];

    printf("Unesite string za proveru: ");
    gets(str);

    printf("\nString pre izbacivanja razmaka: \n'%s'", str);

    int index, i, razmaci = 0;

    // sklanjanje razmaka sa pocetka
    index = 0;
    while(str[index] == ' ')
    {
        index++;
        razmaci++; // prebrojavannje razmaka
    }

    // pomeranje svih karaktera koji nisu razmaci u levo
    i = 0;
    while(str[i + index] != '\0')
    {
        str[i] = str[i + index];
        i++;
    }
    str[i] = '\0'; //NULL karaketer za kraj stringa

    int duzina = strlen(str);
    index = -1;
    for(i = duzina - 1; i >= 0; i--) {
        if(str[i] != ' ') { // naisli smo na prvi karakter koji nije razmak - to ce biti index poslednjeg elementa
            index = i;
            break;
        }
        razmaci++; // brojimo razmake
    }


    // index ce biti poslednji karakter u stringu pre pocetka razmaka na kraju, pa posle njega dodajemo NULL karakter za kraj
    str[index + 1] = '\0';

    printf("\nString posle izbacivanja razmaka: \n'%s'", str);

    printf("\nPreskoceno je %d razmaka.\n", razmaci);

    return 0;
}


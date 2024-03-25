#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define MAX_IME 31

void unos_podataka(char *ime, int *pgodine);
void ispisi_kategoriju(char *ime, int godine);

int main()
{
    char ime[MAX_IME];
    int godine;

    while(1) // beskonacna petlja
    {
        unos_podataka(ime, &godine);
        if(godine == -1) // izlazak iz beskonacne petlje
        {
            break;
        }
        ispisi_kategoriju(ime, godine);
    }
    
    return 0;
}

void unos_podataka(char *ime, int *pgodine)
{
    printf("Unesite ime: ");
    fgets(ime, MAX_IME, stdin);
    int duzina_ime = strlen(ime);
    if(ime[duzina_ime - 1] == '\n')
    {
        ime[duzina_ime - 1] = '\0';
        duzina_ime--;
    }
    else
    {
        __fpurge(stdin);
    }
    
    printf("Unesite godine: ");
    scanf("%d", pgodine);
    __fpurge(stdin);
}

void ispisi_kategoriju(char *ime, int godine)
{
    printf("Osoba %s pripada starosnoj kategoriji: ", ime);

    if(godine >= 0 && godine < 18)
    {
        printf("Dete");
    }
    else if(godine >= 18 && godine < 65)
    {
        printf("Odrasla osoba");
    }
    else if(godine >= 65)
    {
        printf("Penzioner");
    }
    else
    {
        printf("Broj godina mora biti pozitivna vrednost!\n");
    }

    printf("\n");
}
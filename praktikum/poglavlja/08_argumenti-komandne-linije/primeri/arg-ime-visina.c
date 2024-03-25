#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        printf("Primer poziva: %s Vladimir 187.3", argv[0]);
    }
    else
    {
        double visina = atof(argv[2]);

        printf("Osoba %s je ", argv[1]);

        if(visina > 180)
        {
            printf("visa");
        }
        else
        {
            printf("niza");
        }

        printf(" od 180cm.\n");
    }

    return 0;
}

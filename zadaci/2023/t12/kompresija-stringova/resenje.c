#include <stdio.h>
#include <string.h>

#define MAX_STRING 100

int main()
{
    char str[MAX_STRING], str_komp[MAX_STRING];

    printf("Unesite string: ");
    fgets(str, MAX_STRING, stdin);
    int duzina = strlen(str);
    if (str[duzina - 1] == '\n')
    {
        str[duzina - 1] = '\0';
        duzina--;
    }

    int i, j, broj_istih = 1, duzina_komp = 0, desetica, jedinica;

    for (i = 0; i < duzina; i++)
    {
        for (j = i + 1; j < duzina; j++)
        {
            if (str[i] != str[j])
            {
                break;
            }

            broj_istih++;
        }

        desetica = broj_istih / 10;
        jedinica = broj_istih % 10;

        if (desetica > 0)
        {
            str_komp[duzina_komp++] = desetica + '0';
            str_komp[duzina_komp++] = jedinica + '0';
        }
        else if (jedinica > 1)
        {
            str_komp[duzina_komp++] = jedinica + '0';
        }

        str_komp[duzina_komp++] = str[i];

        i += broj_istih - 1;
        broj_istih = 1;
    }

    str_komp[duzina_komp] = '\0';

    printf("String nakon kompresije: %s\n", str_komp);
    printf("Procenat kompresije: %.2lf%%\n", (1 - (double)duzina_komp / duzina) * 100);

    return 0;
}

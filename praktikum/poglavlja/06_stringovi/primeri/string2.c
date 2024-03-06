#include <stdio.h>
#include <string.h>

#define MAX_STRING 30+1

int main()
{
    char str1[MAX_STRING];

    printf("Unesite string: ");
    fgets(str1, MAX_STRING, stdin);
    int duzina_str1 = strlen(str1);
    if (str1[duzina_str1 - 1] == '\n') 
    {
        str1[duzina_str1 - 1] = '\0';
        duzina_str1--;
    }

    int i;
    for (i = 0; i < duzina_str1; i++)
    {
        if (str1[i] >= 65 && str1[i] <= 90)
        {
            str1[i] += 32;
            continue;
        }

        if (str1[i] >= 97 && str1[i] <= 122)
        {
            str1[i] -= 32;
        }
    }

    printf("%s\n", str1);

    return 0;
}

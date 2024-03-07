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

    char *p1 = str1;
    char *p2 = str1 + duzina_str1 - 1;

    while (p1 < p2)
    {
        char temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        
        p1++;
        p2--;
    }

    printf("%s\n", str1);

    return 0;
}


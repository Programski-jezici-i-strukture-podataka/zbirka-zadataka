#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define MAX_STRING 50+1

int main()
{
    char str1[MAX_STRING], str2[MAX_STRING];

    printf("Unesite prvi string: ");
    scanf("%s", str1);
    __fpurge(stdin);

    printf("Unesite drugi string: ");
    fgets(str2, MAX_STRING, stdin);
    int duzina_str2 = strlen(str2);
    if (str2[duzina_str2 - 1] == '\n') 
    {
        str2[duzina_str2 - 1] = '\0';
    }

    printf("\n%s\n", str1);
    printf("%s\n\n", str2);

    return 0;
}


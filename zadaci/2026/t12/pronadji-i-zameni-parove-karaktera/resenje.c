#include <stdio.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>

#define MAX_STR 101

int main() {
    char str[MAX_STR];
    char prvi, drugi;

    printf("Uneti string: ");
    
    fgets(str, MAX_STR, stdin);
    int duzina_str = strlen(str);
    if (str[duzina_str - 1] == '\n') {
        str[duzina_str - 1] = '\0';
    }

    do
    {
        printf("Uneti prvi znak: ");
        scanf("%c", &prvi);
        __fpurge(stdin);
    } while(prvi < 'a' || prvi > 'z');

    do
    {
        printf("Uneti drugi znak: ");
        scanf("%c", &drugi);
        __fpurge(stdin);
    } while(drugi < 'a' || drugi > 'z');

    char *s = str, *t, tmp;
    int zamena;

    while (*s != '\0') {
        zamena = 0;

        if (tolower(*s) == prvi) {
            t = s + 1;
            while (*t != '\0') {
                if (tolower(*t) == drugi) {
                    if (isupper(*s) && islower(*t))
                    {
                        *s = tolower(*s);
                        *t = toupper(*t);
                    }
                    else if (islower(*s) && isupper(*t))
                    {
                        *s = toupper(*s);
                        *t = tolower(*t);
                    }

                    tmp = *s;
                    *s = *t;
                    *t = tmp;

                    s = t;
                    zamena = 1;
                    break;
                }

                t++;
            }

            if(zamena == 0) {
                printf("Ne postoji odgovarajuci broj parova za znakove %c i %c!\n", prvi, drugi);
                break;
            }

        }

        s++;
    }

    printf("String nakon zamene znakova %c i %c: ", prvi, drugi);
    puts(str);


    return 0;
}

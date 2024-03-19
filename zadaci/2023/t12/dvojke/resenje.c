#include <stdio.h>
#include <math.h>

#define MAX_LENGTH 32

int main() {
    int niz[MAX_LENGTH];
    int n, i;
    
    do 
    {
        printf("Unesite velicinu niza: ");
        scanf("%d", &n);
    } while(n <= 0 || n > MAX_LENGTH);
  
    for(i = 0; i < n; i++)
    {
        printf("%d. element niza je: ", i + 1);
        scanf("%d", &niz[i]);
    }
    
    printf("Elementi sa parnim brojem indeksa su: ");
    for(i = 0; i < n; i += 2)
    {
        printf("%d ", niz[i]);
    }
    printf("\n");
    
    printf("Elementi cija apsolutna vrednost je paran broj su: ");
    for(i = 0; i < n; i++)
    {
        if (niz[i] % 2 == 0)
        {
            printf("%d ", niz[i]);
        }
    }
    printf("\n");

    printf("Elementi ciji indeksi su stepen dvojke: ");
    for(i = 1; i < n; i *= 2)
    {
        printf("%d ", niz[i]);
    }
    printf("\n");

    printf("Elementi cija apsolutna vrednost je stepen dvojke: ");
    int temp, stepen;
    for(i = 0; i < n; i++)
    {
        stepen = 1;
        temp = fabs(niz[i]);
        while(temp > 2)
        {
            if (temp % 2 == 0)
            {
                temp = temp / 2;
            }
            else 
            {
                stepen = 0;
                break;
            }
        }
        if (stepen && (niz[i] != 0))
        {
            printf("%d ", niz[i]);
        }
    }
    printf("\n");

    return 0;
}

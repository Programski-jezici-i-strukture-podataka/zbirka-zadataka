#include <stdio.h>

int main()
{
    int i,n;
    printf("Koliko je brojeva potrebno ispisati?\n");
    scanf("%d", &n);

    for(i = 2; i <= 2*n; i += 2) 
    {
        printf("%d ", i);
    }
    printf("\n");
    
    return 0;
}


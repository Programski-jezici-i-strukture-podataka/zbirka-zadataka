#include <stdio.h>
#define MAX 5

int main()
{
    int dobitna[MAX];
    int srecka[MAX];
    int brPogodaka[MAX];
    int i, j, n, k, m = 0;
    int brojac = 0;

    do {
        printf("Unesite maksimalan broj srecki: ");
        scanf("%d", &n);
    } while(n < 1 || n > MAX);

    printf("Unesite dobitnu kombinaciju:\n");
    for(i = 0; i < MAX; i++) {
        scanf("%d", &dobitna[i]);
    }

    for(i = 0; i < n; i++) {
        brojac = 0;
        printf("\nUnesite %d. srecku: \n", i + 1);
        for(j = 0; j < MAX; j++) {
            scanf("%d", &srecka[j]);
            for(k = 0; k < MAX; k++){
                if(srecka[j] == dobitna[k]) {
                    brojac++;
                }
            }
        }
        brPogodaka[m] = brojac;
        m++;
        printf("\n%d. srecka ima %d pogodaka.\n", i + 1, brojac);
    }

    int max = brPogodaka[0];
    int maximalna = 0;
    for(i = 0; i < n; i++) {
        if(brPogodaka[i] >= max){
            maximalna = i;
            max = brPogodaka[i];
        }
    }
    printf("Srecka sa najvise pogodaka je %d.", maximalna + 1);

    return 0;
}

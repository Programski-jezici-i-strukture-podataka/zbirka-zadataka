#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10
#define MAX_STRING 151


int main() {
    int A[MAX_SIZE];
    int n;

    do {
        printf("Unesite broj elemenata niza (max %d): ", MAX_SIZE);
        scanf("%d", &n);
    } while(n<2 || n > MAX_SIZE);

    int i;
    for(i=0; i<n; i++) {
        printf("Unesite A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    printf("\n");
    for(i=0; i<n; i++) {
        printf("A[%d] = %d\n", i, A[i]);
    }

    double sum = 0;
    int count = 0;
    for(i=1; i<n; i+=2) {
        sum += A[i];
        count++;
    }

    double avg = sum / count;
    printf("\n avg = %.1lf\n", avg);

    char B[MAX_STRING];
        
    printf("Unesite string: ");
    __fpurge(stdin);
    gets(B);

    int br=strlen(B);

    printf("Broj karaktera datog citata je %d\n", br);


    char c;
    printf("Unesi karakter: ");
    __fpurge(stdin);
    scanf("%c",&c);

    int brojac;

    for(i = 0; i < strlen(B); i++ )
          if(B[i] == c) {
        brojac++;
    }
    printf("Karakter %c se u datom citatu pojavljuje %d puta\n", c, brojac);

    return 0;
}

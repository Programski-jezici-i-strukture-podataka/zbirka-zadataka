#include <stdio.h>
#include<string.h>

#define MAX_SIZE 10
#define MAX_STRING 151


int main() {
    int A[MAX_SIZE];
    int n, max, fak=1;

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
    max=A[0];
    for(i=1; i<n; i++){
        if(A[i]>max){
            max=A[i];
        }
    }
    for(i = 1; i <= max; i++)
        fak = fak*i;

    printf("Maksimalan element niza A je %d, dok je njegov faktorijel %d.\n", max, fak);

    char B[MAX_STRING];

    printf("Unesite string: ");
    __fpurge(stdin);
    gets(B);

    int br=strlen(B);   
    printf("Broj karaktera datog citata je %d\n", br);

    i=0;
    while(B[i] != '\0') {
        if (B[i] >= 'A' && B[i] <= 'Z'){ 
            B[i] += 32;
        }
        else if (B[i] >= 'a' && B[i] <= 'z'){
            B[i] -= 32;
        }
        i++;
    }
    puts(B);

    return 0;
}

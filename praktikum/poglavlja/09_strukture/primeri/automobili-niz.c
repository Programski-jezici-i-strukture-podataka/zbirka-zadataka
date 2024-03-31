#include <stdio.h>

#define MAX_SIZE 20

typedef struct automobil
{
  char marka[51];
  char model[51];
  int kubikaza;
  int godiste;
  float cena;
}AUTO;
void unos(AUTO*, int *);
void ispis(AUTO*, int);

int main()
{

  AUTO niz[MAX_SIZE];
  int n;
  unos(niz, &n);

  ispis(niz, n);

  return 0;
}

void unos(AUTO* automobili, int *n)
{  
    do 
    {
        printf("Unesite broj automobila: ");
        scanf("%d", n);
    } while(*n <= 0 || *n > MAX_SIZE);

    for (int i = 0; i < *n; i++) 
    {
        printf("\nUnesite marku: ");
        scanf("%s", automobili[i].marka);
        printf("Unesite model: ");
        scanf("%s", automobili[i].model);
        printf("Unesite kubikazu: ");
        scanf("%d", &automobili[i].kubikaza);
        printf("Unesite godiste: ");
        scanf("%d", &automobili[i].godiste);
        printf("Unesite cenu: ");
        scanf("%f", &automobili[i].cena);
    }
}


void ispis(AUTO* automobili, int n) 
{
    for (int i = 0; i < n; i++)
    {
        printf("\nModel autmobila %s marke %s sa kubikazom %d proizveden %d. godine je cene %.2f\n", automobili[i].model, automobili[i].marka, automobili[i].kubikaza, automobili[i].godiste, automobili[i].cena);
    }
}

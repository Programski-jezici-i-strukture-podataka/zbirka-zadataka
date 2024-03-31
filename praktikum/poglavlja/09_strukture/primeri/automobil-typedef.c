#include <stdio.h>

typedef struct automobil
{
  char marka[51];
  char model[51];
  int kubikaza;
  int godiste;
  float cena;
}AUTO;

void unos_automobila(AUTO*);
void ispis_automobila(AUTO);

int main()
{

  AUTO a1, a2;
  unos_automobila(&a1);
  printf("\n");
  unos_automobila(&a2);

  ispis_automobila(a1);
  ispis_automobila(a2);

  return 0;
}


void unos_automobila(AUTO* a)
{
  printf("Unesite marku: ");
  scanf("%s", a->marka);
  printf("Unesite model: ");
  scanf("%s", (*a).model);
  printf("Unesite kubikazu: ");
  scanf("%d", &(a->kubikaza));
  printf("Unesite godiste: ");
  scanf("%d", &((*a).godiste));
  printf("Unesite cenu: ");
  scanf("%f", &(a->cena));
}

void ispis_automobila(AUTO a) 
{
  printf("\nModel autmobila %s marke %s sa kubikazom %d proizveden %d. godine je cene %.2f\n", a.model, a.marka, a.kubikaza, a.godiste, a.cena);
}

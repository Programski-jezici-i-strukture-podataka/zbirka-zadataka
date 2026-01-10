#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NAZIV_TIMA 15+1
#define MAX_NAZIV_VOZACA 10+1
#define MAX_NIZ 11

typedef struct formula_st
{
    char naziv_tima[MAX_NAZIV_TIMA];
    char naziv_vozaca[MAX_NAZIV_VOZACA];
    unsigned int vreme_po_krugu;
    double penali;
    double ukupno_vreme;
} Formula;

void ucitavanje(Formula *f, int *n, int br_krugova)
{
    int i;

    do
    {
        printf("Unesite broj timova: ");
        scanf("%d", n);
    } while (*n <= 0 || *n > MAX_NIZ);

    for(i = 0;i < *n;i++)
    {
        printf("%d. tim: ", i + 1);
        scanf("%s %s %u %lf",
            f[i].naziv_tima,
            f[i].naziv_vozaca,
            &f[i].vreme_po_krugu,
            &f[i].penali);
        f[i].ukupno_vreme = f[i].vreme_po_krugu * br_krugova + f[i].penali;
    }
}

void ukupna_vremena_timova(Formula *f,int n) 
{
    int i;
    double sumaF=0.0,sumaR=0.0,sumaMerc=0.0,sumaMcLaren=0.0,sumaA=0.0;
    printf("Ukupna vremena timova su:\n");
    for(i=0;i<n;i++)
    {
        if(strcmp(f[i].naziv_tima,"Ferrari") == 0)
        {
            sumaF+=f[i].ukupno_vreme;
        }else if(strcmp(f[i].naziv_tima,"Red_Bull_Racing") == 0)
        {
            sumaR+=f[i].ukupno_vreme;
        }else if(strcmp(f[i].naziv_tima,"Mercedes") == 0)
        {
            sumaMerc+=f[i].ukupno_vreme;
        }else if(strcmp(f[i].naziv_tima,"McLaren") == 0)
        {
            sumaMcLaren+=f[i].ukupno_vreme;
        }else if(strcmp(f[i].naziv_tima,"Alpine") == 0)
        {
            sumaA+=f[i].ukupno_vreme;
        }
    }
    
    printf("Ferrari: %.1lf\n",sumaF);
    printf("Red_Bull_Racing: %.1lf\n",sumaR);
    printf("Mercedes: %.1lf\n",sumaMerc);
    printf("McLaren: %.1lf\n",sumaMcLaren);
    printf("Alpine: %.1lf\n",sumaA);
            
}

void najbolji_vozac(Formula *f,int n)
{
    int i,index;
    Formula min=f[0];
    
    printf("\nNajbolji vozac je:\n");
    for(i=1;i<n;i++)
    {
        if(min.ukupno_vreme > f[i].ukupno_vreme)
            min=f[i];
    }
    
    printf("%s iz tima %s sa ukupnim vremenom %.1lf sekundi.\n",min.naziv_vozaca,min.naziv_tima,min.ukupno_vreme);
    
}

//primer poziva ./a.out 60 < timovi-stdinout.txt
int main(int brojArgum, char **argumenti)
{
    Formula f[MAX_NIZ];
    int n;
    
    if(brojArgum != 2)
    {
        printf("Pogresan broj unetih argumenata!");
        exit(1);
    }

    ucitavanje(f,&n,atoi(argumenti[1]));
    printf("\n\n");
    ukupna_vremena_timova(f,n);
    najbolji_vozac(f,n);
    
    return 0;
}


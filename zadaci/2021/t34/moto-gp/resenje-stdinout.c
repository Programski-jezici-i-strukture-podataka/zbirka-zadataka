#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MARKA 7+1
#define MAX_TIP_GUME 5+1
#define MAX_NIZ 8

typedef struct motor_st
{
    char marka[MAX_MARKA];
    double snaga;
    double vreme_po_krugu;
    int procenat_trosenja;
    char tip_gume[MAX_TIP_GUME];
    int broj_stajanja;
} Motor;

void ucitavanje(Motor *m, int *n)
{
    int i;

    do
    {
        printf("Unesite broj motora: ");
        scanf("%d", n);
    } while (*n <= 0 || *n > MAX_NIZ);

    for(i = 0;i < *n;i++)
    {
        printf("%d. motor: ", i + 1);
        scanf("%s %lf %lf %d %s",
            m[i].marka, 
            &m[i].snaga,
            &m[i].vreme_po_krugu,
            &m[i].procenat_trosenja,
            m[i].tip_gume);
        m[i].snaga = m[i].snaga * 1.36;
    }
}

void sa_jednim_setom(Motor *m,int n)
{
    int i,krugovi=0;
    printf("Sa jednim setom guma motori mogu preci:\n");
    for(i=0;i<n;i++)
    {
        printf("%s moze preci %d krugova.\n",m[i].marka,100/m[i].procenat_trosenja);
    }
}

void promena_guma(Motor *m, int n, int br_kruga)
{
    int i,broj_stajanja=0;
    printf("\nRezultati nakon trke su:\n");
    printf("\nNaziv\tSnaga\tVreme_po_krugu\tBroj_stajanja\n");
    for(i=0;i<n;i++)
    {
        m[i].broj_stajanja = br_kruga / (100/m[i].procenat_trosenja);
        if(strlen(m[i].marka) > 3)
            printf("%s\t%.1lfks\t\t%.2lfs\t\t\t%d\n",m[i].marka,m[i].snaga,m[i].vreme_po_krugu,m[i].broj_stajanja);
        else
            printf("%s\t\t%.1lfks\t\t%.2lfs\t\t\t%d\n",m[i].marka,m[i].snaga,m[i].vreme_po_krugu,m[i].broj_stajanja);
    }
}

void ukupno_potroseno_guma(Motor *m, int n, char *tip)
{
    int i,suma=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(m[i].tip_gume, tip) == 0)
        {
            suma+=m[i].broj_stajanja*2;
        }
    }
    printf("\nUkupno je potroseno %d guma tipa %s.\n",suma,tip);
}

//primer poziva ./a.out 25 Medium < motori-stdinout.txt
int main(int brojArgum, char **argumenti)
{
    Motor m[MAX_NIZ];
    int n;
    
    if(brojArgum != 3)
    {
        printf("Pogresan broj unetih argumenata!");
        exit(1);
    }

    ucitavanje(m,&n);
    printf("\n\n");
    sa_jednim_setom(m,n);
    promena_guma(m,n,atoi(argumenti[1]));

    ukupno_potroseno_guma(m,n,argumenti[2]);

    return 0;
}


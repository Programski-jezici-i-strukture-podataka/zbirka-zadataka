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
}Motor;

FILE *otvori(char *name,char *mode)
{
    FILE *f = fopen(name,mode);
    
    if(f == NULL)
    {
        printf("Problem prilikom otvaranja %s datoteke.",name);
        exit(2);
    }

    return f;
}

void ucitavanje(FILE *in, Motor *m, int *n)
{
    *n=0;
    while(fscanf(in,"%s %lf %lf %d %s",m[*n].marka, &m[*n].snaga, &m[*n].vreme_po_krugu, &m[*n].procenat_trosenja, m[*n].tip_gume) != EOF)
    {
        m[*n].snaga = m[*n].snaga * 1.36;
        (*n)++;
    }
}

void sa_jednim_setom(FILE *out, Motor *m,int n)
{
    int i,krugovi=0;
    fprintf(out,"Sa jednim setom guma motori mogu preci:\n");
    for(i=0;i<n;i++)
    {
        fprintf(out,"%s moze preci %d krugova.\n",m[i].marka,100/m[i].procenat_trosenja);
    }
}

void promena_guma(FILE *out, Motor *m, int n, int br_kruga)
{
    int i,broj_stajanja=0;
    fprintf(out,"\nRezultati nakon trke su:\n");
    fprintf(out,"\nNaziv\tSnaga\tVreme_po_krugu\tBroj_stajanja\n");
    for(i=0;i<n;i++)
    {
        m[i].broj_stajanja = br_kruga / (100/m[i].procenat_trosenja);
        if(strlen(m[i].marka) > 3)
            fprintf(out,"%s\t%.1lfks\t\t%.2lfs\t\t\t%d\n",m[i].marka,m[i].snaga,m[i].vreme_po_krugu,m[i].broj_stajanja);
        else
            fprintf(out,"%s\t\t%.1lfks\t\t%.2lfs\t\t\t%d\n",m[i].marka,m[i].snaga,m[i].vreme_po_krugu,m[i].broj_stajanja);
    }
}

void ukupno_potroseno_guma(FILE *out, Motor *m, int n, char *tip)
{
    int i,suma=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(m[i].tip_gume, tip) == 0)
        {
            suma+=m[i].broj_stajanja*2;
        }
    }
    fprintf(out,"\nUkupno je potroseno %d guma tipa %s.\n",suma,tip);
}

//primer poziva ./a.out motori.txt statistika.txt 25 Medium
int main(int brojArgum, char **argumenti)
{
    Motor m[MAX_NIZ];
    FILE *in,*out;
    int n;
    
    if(brojArgum != 5)
    {
        printf("Pogresan broj unetih argumenata!");
        exit(1);
    }

    in = otvori(argumenti[1],"r");
    out = otvori(argumenti[2],"w");

    ucitavanje(in,m,&n);
    sa_jednim_setom(out,m,n);
    promena_guma(out,m,n,atoi(argumenti[3]));

    ukupno_potroseno_guma(out,m,n,argumenti[4]);
    
    fclose(in);
    fclose(out);
    
    return 0;
}


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
}Formula;

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

void ucitavanje(FILE *in, Formula *f, int *n, int br_krugova)
{
    *n=0;
    while(fscanf(in,"%s %s %u %lf",f[*n].naziv_tima,f[*n].naziv_vozaca,&f[*n].vreme_po_krugu,&f[*n].penali) != EOF)
    {
        f[*n].ukupno_vreme = f[*n].vreme_po_krugu * br_krugova + f[*n].penali;  
        (*n)++;
    }
}

void ukupna_vremena_timova(FILE *out, Formula *f,int n) 
{
    int i;
    double sumaF=0.0,sumaR=0.0,sumaMerc=0.0,sumaMcLaren=0.0,sumaA=0.0;
    fprintf(out,"Ukupna vremena timova su:\n");
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
    
    fprintf(out,"Ferrari: %.1lf\n",sumaF);
    fprintf(out,"Red_Bull_Racing: %.1lf\n",sumaR);
    fprintf(out,"Mercedes: %.1lf\n",sumaMerc);
    fprintf(out,"McLaren: %.1lf\n",sumaMcLaren);
    fprintf(out,"Alpine: %.1lf\n",sumaA);
            
}

void najbolji_vozac(FILE *out, Formula *f,int n)
{
    int i,index;
    Formula min=f[0];
    
    fprintf(out,"\nNajbolji vozac je:\n");
    for(i=1;i<n;i++)
    {
        if(min.ukupno_vreme > f[i].ukupno_vreme)
            min=f[i];
    }
    
    fprintf(out,"%s iz tima %s sa ukupnim vremenom %.1lf sekundi.\n",min.naziv_vozaca,min.naziv_tima,min.ukupno_vreme);
    
}

//primer poziva ./a.out 60 statistika.txt timovi.txt
int main(int brojArgum, char **argumenti)
{
    Formula f[MAX_NIZ];
    FILE *in,*out;
    int n;
    
    if(brojArgum != 4)
    {
        printf("Pogresan broj unetih argumenata!");
        exit(1);
    }

    in = otvori(argumenti[3],"r");
    out = otvori(argumenti[2],"w");

    ucitavanje(in,f,&n,atoi(argumenti[1]));
    ukupna_vremena_timova(out,f,n);
    najbolji_vozac(out,f,n);

    fclose(in);
    fclose(out);
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_KATEGORIJA 21
#define MAX_NAZIV 21

typedef struct cvor_st{
    char kategorija[MAX_KATEGORIJA];
    char naziv[MAX_NAZIV];
    float cena;
    float ukupna_cena;
    struct cvor_st* sledeci;
}CVOR;

FILE* open_file(char* ime, char* mode) {

    FILE* fp = fopen(ime, mode);
    if(fp==NULL) 
    {
        printf("Greska pri otvaranju datoteke %s\n", ime);
        exit(2);
    }
    return fp;
}

void init(CVOR** glava) {
    *glava = NULL;
}

CVOR* create_node(char* kategorija, char* naziv, float cena, float povrsina) {
    CVOR* tmp = malloc(sizeof(CVOR));
    if(tmp==NULL)
    {
        printf("Ne moze se zauzeti memorija\n");
        exit(3);
    }
    strcpy(tmp->kategorija, kategorija);
    strcpy(tmp->naziv, naziv);
    tmp->cena = cena;
    tmp->ukupna_cena = cena * povrsina;
    tmp->sledeci = NULL;
    return tmp; 
}

void add_sorted(CVOR** glava, CVOR* novi) {

   CVOR* trenutni;
    if(*glava==NULL || (*glava)->cena >= novi->cena) 
    {
        novi->sledeci = *glava;
        *glava = novi;
    } else 
    {
        trenutni = *glava;
        while(trenutni->sledeci!=NULL && trenutni->sledeci->cena < novi->cena)
        {
            trenutni = trenutni->sledeci;
        }
        novi->sledeci = trenutni->sledeci;
        trenutni->sledeci = novi;
    }
}

void read(FILE* in, CVOR** glava, float povrsina) {
    char kategorija[MAX_KATEGORIJA], naziv[MAX_NAZIV];
    float cena;
    while(fscanf(in, "%s %s %f", kategorija, naziv, &cena)
    !=EOF)
    {
        CVOR* new = create_node(kategorija, naziv, cena, povrsina);
        add_sorted(glava, new);
    }
}

void write(FILE* out, CVOR* glava, CVOR* najblizi) {
    while(glava != NULL) 
    {
        fprintf(out, "%12s %12s %12.2f$ %12.2f$\n", glava->kategorija, glava->naziv,
            glava->cena, glava->ukupna_cena);
        glava = glava->sledeci;
    }
    if(najblizi == NULL){
    	fprintf(out, "\nNe postoji materijal te kategorije\n");
    }
    else{
    	fprintf(out, "\nMaterijal kategorije %s najblizi zeljenoj vrednosti je %s\n",najblizi->kategorija, najblizi->naziv);
    }
}

CVOR* nadji_najblizi(CVOR* glava, char* kategorija, float zeljeno){
    CVOR* tmp = glava;
    CVOR* najblizi = NULL;
    while(tmp != NULL) 
    {
        if(!strcmp(tmp->kategorija, kategorija)){
            if(najblizi == NULL){
            	najblizi = tmp;
            }
            if(fabs(zeljeno - najblizi->ukupna_cena) > fabs(zeljeno - tmp->ukupna_cena)){
            	najblizi = tmp;
            }
        }
        tmp = tmp->sledeci;
    }
    return najblizi;
}

void clear(CVOR** glava) {
    CVOR *tmp;
    while(*glava != NULL)
    {
        tmp = *glava;
        *glava = (*glava)->sledeci;
        tmp->sledeci = NULL;
        free(tmp);
    }
}

int main(int argc, char* argv[]) {
    
    if(argc!=6) 
    {
        printf("Primer poziva programa: ./a.out input.txt output.txt 3.5 1200 Drvo\n");
        exit(1);
    }
    
    FILE* in = open_file(argv[1], "r");
    FILE* out = open_file(argv[2], "w");
    CVOR* glava;
    init(&glava);
    read(in, &glava, atof(argv[3]));
    CVOR* najblizi = nadji_najblizi(glava,argv[5],atof(argv[4]));
    write(out, glava, najblizi);
    
    fclose(in);
    fclose(out);
    clear(&glava);
    return 0;
}

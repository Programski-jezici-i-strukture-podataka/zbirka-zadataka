#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_OZNAKA 9
#define MAX_ISPORUCEN 3

typedef struct paket{
    char oznaka[MAX_OZNAKA];
    float cena;
    unsigned udaljenost;
    char isporucen[MAX_ISPORUCEN];
    struct paket *sledeci;
} PAKET;

void inicijalizacija(PAKET **);
PAKET *napraviCvor(char *, float, int, char *);
FILE *safeFopen(char *, char *, int);
void ucitajStavke(FILE *, PAKET **);
void dodajNaKraj(PAKET **, PAKET *);
void izracunaj(FILE *, PAKET *, int);
void obrisiListu(PAKET **);

int main(int argc, char **argv) {
    PAKET*glava;

    if(argc != 4) {
        printf("Primer poziva: %s paketi.txt isporuka.txt 5\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    inicijalizacija(&glava);
    
    FILE *in = safeFopen(argv[1], "r", 1);
    ucitajStavke(in, &glava);
    fclose(in);
    
    int maxUdaljenost = atoi(argv[3]);
    

    
    FILE *out = safeFopen(argv[2], "w", 2);
    
    izracunaj(out, glava, maxUdaljenost);
    
    fclose(out);
    obrisiListu(&glava);
  
    return EXIT_SUCCESS;
   
}

FILE *safeFopen(char *name, char *mode, int errorCode) {
    FILE *fp = fopen(name, mode);

    if(fp == NULL) {
        printf("Greska prilikom otvaranja fajla %s!\n", name);
        exit(errorCode);
    }

    return fp;
}

void ucitajStavke(FILE *in, PAKET **glava) {
   	char oznaka[MAX_OZNAKA];
    float cena;
    int udaljenost;
    char isporucen[MAX_ISPORUCEN];
    PAKET *novi;

    while(fscanf(in, "%s %f %s %u",
                 oznaka, &cena, isporucen, &udaljenost)
    != EOF) {
        novi = napraviCvor(
                   oznaka, cena, udaljenost, isporucen);
        dodajNaKraj(glava, novi);
    }
}

void izracunaj(FILE *out, PAKET *glava, int maxUdaljenost) {
    PAKET *tekuci = glava;
    
    while(tekuci != NULL) {
    	if(strcmp(tekuci->isporucen, "ne") == 0) {
    		if(tekuci->udaljenost <= maxUdaljenost){
    			fprintf(out, "%s %.2f %u, cena isporuke %.2f din\n", tekuci->oznaka, tekuci->cena, tekuci->udaljenost, tekuci->cena+50);
			}
			else {
				fprintf(out, "%s %.2f %u, cena isporuke %.2f din\n", tekuci->oznaka, tekuci->cena, tekuci->udaljenost, tekuci->cena+(tekuci->cena/2));
			}
    	}
    	
        tekuci = tekuci->sledeci;
    }
}

void inicijalizacija(PAKET **glava) {
    *glava = NULL;
}

PAKET *napraviCvor(char *oznaka, float cena, int udaljenost, char *isporucen) {
    PAKET *novi = (PAKET *)malloc(sizeof(PAKET));

    if(novi == NULL) {
        printf("Nije moguce zauzeti memoriju!\n");
        exit(EXIT_FAILURE);
    }
   
    strcpy(novi->oznaka, oznaka);
    strcpy(novi->isporucen, isporucen);
    novi->cena = cena;
    novi->udaljenost = udaljenost;
    novi->sledeci = NULL;

    return novi;
}

void dodajNaKraj(PAKET **glava, PAKET *novi) {
	if(*glava == NULL) {
 		*glava = novi;
 	} else {
 	
 		PAKET *tekuci = *glava;
 		while(tekuci->sledeci != NULL) {
 			tekuci = tekuci->sledeci;
 		}
 		tekuci->sledeci = novi;
 	}
}

void obrisiListu(PAKET **glava) {
    PAKET *tmp;

    while(*glava != NULL) {
        tmp = *glava;
        *glava = (*glava)->sledeci;
        tmp->sledeci = NULL;
        free(tmp);
    }
}

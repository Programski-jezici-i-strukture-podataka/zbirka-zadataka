#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INDEX 11
#define MAX_IME_PREZIME 16

typedef struct student{
    char index[MAX_INDEX];
    char ime[MAX_IME_PREZIME];
    char prezime[MAX_IME_PREZIME];
    unsigned o1;
    unsigned o2;
    unsigned o3;
    unsigned o4;
    unsigned o5;
    struct student *sledeci;
} STUDENT;

void inicijalizacija(STUDENT **);
STUDENT *napraviCvor(char *, char *, char *, unsigned, unsigned, unsigned, unsigned, unsigned);
FILE *safeFopen(char *, char *, int);
void ucitajStavke(FILE *, STUDENT **);
void dodajNaKraj(STUDENT **, STUDENT *);
void izracunaj(FILE *, STUDENT *);
void obrisiListu(STUDENT **);

int main(int argc, char **argv) {
    STUDENT *glava;

    if(argc != 3) {
        printf("Primer poziva: %s studenti.txt polozili.txt\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    inicijalizacija(&glava);
    
    FILE *in = safeFopen(argv[1], "r", 1);
    ucitajStavke(in, &glava);
    fclose(in);
  
    FILE *out = safeFopen(argv[2], "w", 2);
    
    izracunaj(out, glava);
    
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

void ucitajStavke(FILE *in, STUDENT **glava) {
   	char index[MAX_INDEX];
    char ime[MAX_IME_PREZIME];
    char prezime[MAX_IME_PREZIME];
    unsigned o1;
    unsigned o2;
    unsigned o3;
    unsigned o4;
    unsigned o5;
    STUDENT *novi;

    while(fscanf(in, "%s %s %s %u %u %u %u %u",
                 index, ime, prezime, &o1, &o2, &o3, &o4, &o5)
    != EOF) {
        novi = napraviCvor(
                   index, ime, prezime, o1, o2, o3, o4, o5);
        dodajNaKraj(glava, novi);
    }
}

void izracunaj(FILE *out, STUDENT *glava) {
    STUDENT *tekuci = glava;
    int brojPolozenih;
    while(tekuci != NULL) {
    	brojPolozenih = 0;
    	if(tekuci->o1 > 5){
    		brojPolozenih++;
		}
		if(tekuci->o2 > 5){
    		brojPolozenih++;
		}
		if(tekuci->o3 > 5){
    		brojPolozenih++;
		}
		if(tekuci->o4 > 5){
    		brojPolozenih++;
		}
		if(tekuci->o5 > 5){
    		brojPolozenih++;
		}
		
		if(brojPolozenih == 5){
			fprintf(out, "%s %s %s %u %u %u %u %u, budzet\n", tekuci->index, tekuci->ime, tekuci->prezime, tekuci->o1, tekuci->o2, tekuci->o3, tekuci->o4, tekuci->o5);
		}
		else if(brojPolozenih == 4){
			fprintf(out, "%s %s %s %u %u %u %u %u, samofinansiranje\n", tekuci->index, tekuci->ime, tekuci->prezime, tekuci->o1, tekuci->o2, tekuci->o3, tekuci->o4, tekuci->o5);
		}
    	
        tekuci = tekuci->sledeci;
    }
}

void inicijalizacija(STUDENT **glava) {
    *glava = NULL;
}

STUDENT *napraviCvor(char *index, char *ime, char *prezime, unsigned o1, unsigned o2, unsigned o3, unsigned o4, unsigned o5) {
    STUDENT *novi = (STUDENT *)malloc(sizeof(STUDENT));

    if(novi == NULL) {
        printf("Nije moguce zauzeti memoriju!\n");
        exit(EXIT_FAILURE);
    }
   
    strcpy(novi->index, index);
    strcpy(novi->ime, ime);
    strcpy(novi->prezime, prezime);
    novi->o1 = o1;
    novi->o2 = o2;
    novi->o3 = o3;
    novi->o4 = o4;
    novi->o5 = o5;
    novi->sledeci = NULL;

    return novi;
}

void dodajNaKraj(STUDENT **glava, STUDENT *novi) {
	if(*glava == NULL) {
 		*glava = novi;
 	} else {
 	
 		STUDENT *tekuci = *glava;
 		while(tekuci->sledeci != NULL) {
 			tekuci = tekuci->sledeci;
 		}
 		tekuci->sledeci = novi;
 	}
}

void obrisiListu(STUDENT **glava) {
    STUDENT *tmp;

    while(*glava != NULL) {
        tmp = *glava;
        *glava = (*glava)->sledeci;
        tmp->sledeci = NULL;
        free(tmp);
    }
}

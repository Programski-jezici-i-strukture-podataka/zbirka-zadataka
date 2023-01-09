// primer poziva programa:
// ./zad Academy skole.txt izvestaj.txt

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define NAZIV 30+1
#define GRAD 2+1
#define PRVI_JEZIK 15+1
#define DRUGI_JEZIK 15+1
#define NIVO 8+1

typedef struct skola_jezika_st {
	char naziv[NAZIV];
	char grad[GRAD];
	char prviStraniJezik[PRVI_JEZIK];
	char drugiStraniJezik[DRUGI_JEZIK];
	char nivo[NIVO];
	float osnovnaCenaKursa;
	unsigned brojPolaznikaPoGrupi;
	float cenaSaPopustom;
	struct skola_jezika_st* levi;
	struct skola_jezika_st* desni;
}SKOLA;

void inicijalizacija(SKOLA **koren) {
	*koren = NULL;
}

void dodaj(SKOLA **koren, SKOLA *novi) {
	if(*koren == NULL) {
		*koren = novi;
	} else if(novi->osnovnaCenaKursa >= (*koren)->osnovnaCenaKursa) {
		dodaj(&((*koren)->levi),novi);
	} else {
		dodaj(&((*koren)->desni),novi);
	}
}

SKOLA *napravi_cvor(char naziv[], char grad[], char prviStraniJezik[], char drugiStraniJezik[],
                    char nivo[], float osnovnaCenaKursa, unsigned brojPolaznikaPoGrupi) {
	SKOLA *novi = (SKOLA *)malloc(sizeof(SKOLA));
	if (novi == NULL) {
		printf("\tNema dovoljno memorije!\n");
		exit(4);
	}

	strcpy(novi->naziv, naziv);
	strcpy(novi->grad, grad);
	strcpy(novi->prviStraniJezik, prviStraniJezik);
	strcpy(novi->drugiStraniJezik, drugiStraniJezik);
	strcpy(novi->nivo, nivo);
	novi->osnovnaCenaKursa = osnovnaCenaKursa;
	novi->brojPolaznikaPoGrupi = brojPolaznikaPoGrupi;

	//konacno
	if(novi->brojPolaznikaPoGrupi > 3 && novi->brojPolaznikaPoGrupi < 7) { //5%
		novi->cenaSaPopustom = novi->osnovnaCenaKursa * 0.95;
	} else if(novi->brojPolaznikaPoGrupi >= 7 && novi->brojPolaznikaPoGrupi < 10) { //10%
		novi->cenaSaPopustom = novi->osnovnaCenaKursa * 0.9;
	} else if(novi->brojPolaznikaPoGrupi >= 10) {
		novi->cenaSaPopustom = novi->osnovnaCenaKursa * 0.85;
	} else {
		novi->cenaSaPopustom = novi->osnovnaCenaKursa;
	}

	novi->levi = NULL;
	novi->desni = NULL;

	return novi;
}

void ucitaj(FILE *in, SKOLA **koren) {
	char naziv[NAZIV];
	char grad[GRAD];
	char prviStraniJezik[PRVI_JEZIK];
	char drugiStraniJezik[DRUGI_JEZIK];
	char nivo[NIVO];
	float osnovnaCenaKursa;
	unsigned brojPolaznikaPoGrupi;

	while(fscanf(in, "%s %s %s %s %s %f %u", naziv, grad, prviStraniJezik, drugiStraniJezik,
                 nivo, &osnovnaCenaKursa, &brojPolaznikaPoGrupi) != EOF) {
		SKOLA *novi = napravi_cvor(naziv, grad, prviStraniJezik, drugiStraniJezik,
                                   nivo, osnovnaCenaKursa, brojPolaznikaPoGrupi);
		dodaj(koren, novi);
	}
}

void ispisi_stablo(FILE *out, SKOLA *koren) {
	if(koren != NULL) {
		ispisi_stablo(out, koren->levi);
		fprintf(out, "%s %s %u %.3lf %s %s\n", koren->naziv, koren->grad, koren->brojPolaznikaPoGrupi,
                koren->cenaSaPopustom, koren->prviStraniJezik, koren->drugiStraniJezik);
		ispisi_stablo(out, koren->desni);
	}
}

void obrisi_stablo(SKOLA **koren) {
	if(*koren != NULL) {
		obrisi_stablo(&((*koren)->levi));
		obrisi_stablo(&((*koren)->desni));
		free(*koren);
		*koren = NULL;
	}
}

FILE *safe_fopen(char *imeDatoteke, char *rezim) {
    FILE *fp = fopen(imeDatoteke, rezim);
    
	if (fp == NULL) {
        printf("Problem prilikom otvaranja %s datoteke!\n", imeDatoteke);
        exit(33);
    }
	
    return fp;
}

SKOLA *nemackiKaoDrugiJezik(FILE *izlazna, SKOLA *koren) {
	if (koren == NULL) {
		return NULL;
	}

	//samo skole u kojima se nemacki uci kao drugi strani jezik
	SKOLA *skola = NULL;
	if(strcmp(koren->drugiStraniJezik, "nemacki") == 0) {
		skola = koren;
	}

	//obilazak levog podstabla
	SKOLA *skolaL = nemackiKaoDrugiJezik(izlazna, koren->levi);
	if(skolaL != NULL) {
		if(skola == NULL || skolaL->cenaSaPopustom < skola->cenaSaPopustom) {
			skola = skolaL;
		}
	}

	//obilazak desnog podstabla
	SKOLA *skolaD = nemackiKaoDrugiJezik(izlazna, koren->desni);
	if(skolaD != NULL) {
		if(skola == NULL || skolaD->cenaSaPopustom < skola->cenaSaPopustom) {
			skola = skolaD;
		}
	}

	return skola;
}

SKOLA *polazniciFrancuski(FILE *out, SKOLA *koren, char *odabranaSkola) {
	if(koren == NULL) {
		return NULL;
	}

	//samo skole u kojima se francuski uci kao prvi strani jezik
	SKOLA *skola = NULL;
	if(strcmp(koren->naziv, odabranaSkola) == 0 && strcmp(koren->prviStraniJezik, "francuski") == 0) {
		skola = koren;
	}

	//obilazak levog podstabla
	SKOLA *skolaL = polazniciFrancuski(out, koren->levi, odabranaSkola);
	if(skolaL != NULL) {
		if(skola == NULL || skolaL->osnovnaCenaKursa > skola->osnovnaCenaKursa) {
			skola = skolaL;
		}
	}

	//obilazak desnog podstabla
	SKOLA *skolaD = polazniciFrancuski(out, koren->desni, odabranaSkola);
	if(skolaD != NULL) {
		if(skola == NULL || skolaD->osnovnaCenaKursa > skola->osnovnaCenaKursa) {
			skola = skolaD;
		}
	}

	return skola;
}

int main(int brArg, char *args[]) {
	if(brArg != 4) {
		printf("Pogresan unos argumenata!\n");
		exit(3);
	}

	FILE *in = safe_fopen(args[2], "r");
	FILE *out = safe_fopen(args[3], "w");

	SKOLA *koren;

	inicijalizacija(&koren);
	ucitaj(in, &koren);
	ispisi_stablo(out, koren);

	SKOLA *skolaNemacki = nemackiKaoDrugiJezik(out, koren);	
	fprintf(out, "\n\nSkola jezika u kojoj se nemacki uci kao drugi strani jezik a cija je cena sa popustom najniza: %s %s %.3lf",
            skolaNemacki->naziv, skolaNemacki->grad, skolaNemacki->cenaSaPopustom);

	SKOLA *skolaPolazniciFrancuski = polazniciFrancuski(out, koren, args[1]);

	if(skolaPolazniciFrancuski)
		fprintf(out, "\n\nBroj polaznika skole %s koji kao prvi strani jezik uci francuski a cija je osnovna cena kursa (%.3lf): %d.",
                skolaPolazniciFrancuski->naziv, skolaPolazniciFrancuski->osnovnaCenaKursa, skolaPolazniciFrancuski->brojPolaznikaPoGrupi);
	else
		fprintf(out,"\n\nNema trazene skole!");

	obrisi_stablo(&koren);

	fclose(in);
	fclose(out);

	return 0;
}

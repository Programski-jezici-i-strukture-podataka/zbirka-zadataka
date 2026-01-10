#ifndef LISTA_H
#define LISTA_H
#define MAX_KATEGORIJA 21
#define MAX_NAZIV 21
typedef struct cvor_st{
    char kategorija[MAX_KATEGORIJA];
    char naziv[MAX_NAZIV];
    float cena;
    float ukupna_cena;
    struct cvor_st* sledeci;
}CVOR;

void init(CVOR** glava);
CVOR* create_node(char* kategorija, char* naziv, float cena, float povrsina);
void add_sorted(CVOR** glava, CVOR* novi);
void clear(CVOR** glava);

#endif

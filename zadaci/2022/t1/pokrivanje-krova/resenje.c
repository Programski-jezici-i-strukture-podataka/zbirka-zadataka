#include <stdio.h>
#include <math.h>

#define MAX_NIZ 20

int main() {
    int povrsine_crepova[MAX_NIZ];
    double cene_crepova[MAX_NIZ], povrsina_za_pokrivanje, ukupne_cene_materijala[MAX_NIZ];
    int i, n;

    do {
        printf("Ucitati broj modela crepova: ");
        scanf("%d", &n);
    } while(n <= 0 || n > MAX_NIZ);

    for(i = 0;i < n;i++) {
        printf("%d. model crepa\n", i + 1);
        printf("povrsina [cm2]: ");
        scanf("%d", &povrsine_crepova[i]);
        printf("cena [RSD]: ");
        scanf("%lf", &cene_crepova[i]);
        printf("\n");
    }

    do {
        printf("Uneti povrsinu koju je potrebno pokriti [m2]: ");
        scanf("%lf", &povrsina_za_pokrivanje);
    } while(povrsina_za_pokrivanje <= 0);

    double povrsina_za_pokrivanje_cm2 = povrsina_za_pokrivanje * 10000;
    for(i = 0;i < n;i++) {
        ukupne_cene_materijala[i] = povrsina_za_pokrivanje_cm2 / povrsine_crepova[i] * cene_crepova[i];
    }

    printf("\nUkupne cene u dinarima: [");
    for(i = 0;i < n;i++) {
        if(i > 0) {
            printf(", ");
        }
        printf("%.2lf", ukupne_cene_materijala[i]);
    }
    printf("]\n");

    int indeks_najpovoljnijeg = 0;
    double najpovoljniji_materijal = ukupne_cene_materijala[0];

    for(i = 1;i < n;i++) {
        if(ukupne_cene_materijala[i] < najpovoljniji_materijal) {
            indeks_najpovoljnijeg = i;
            najpovoljniji_materijal = ukupne_cene_materijala[i];
        }
    }

    printf("Najpovoljniji je %d. crep, cija ukupna cena za pokrivanje %.2lf metara kvadratnih iznosi %.2lf dinara.\n",
        indeks_najpovoljnijeg + 1, povrsina_za_pokrivanje, najpovoljniji_materijal);

    int indeks_najveceg_crepa = 0;

    for(i = 1;i < n;i++) {
        if(povrsine_crepova[i] > povrsine_crepova[indeks_najveceg_crepa]) {
            indeks_najveceg_crepa = i;
        }
    }

    printf("Najmanje potrebno za pokrivanje %.2lf metara kvadratnih ukoliko se koristi %d. crep: %d komada.\n",
        povrsina_za_pokrivanje, indeks_najveceg_crepa + 1, (int)ceil(povrsina_za_pokrivanje_cm2 / povrsine_crepova[indeks_najveceg_crepa]));

    return 0;
}


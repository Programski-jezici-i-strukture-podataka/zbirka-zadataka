#include <stdio.h>
#include <string.h>

#define MAX_NIZ 20


int main() {

    int cigla[MAX_NIZ], crep[MAX_NIZ], n, maxIndex;
    float cena_maltera, malter[MAX_NIZ], cena_cigle, cena_crepa, ukupno = 0, ukupno_cigle = 0, max;

    do {
        printf("Unesite broj dana radova: ");
        scanf("%d", &n);
    } while (n < 0 || n > 20);

    for (int i = 0; i < n; i++) {
        printf("Unesite potrosenu kolicinu maltera u kg za %d. dan: ", i+1);
        scanf("%f", &malter[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("Unesite potrosenu kolicinu cigle u komadima za %d. dan: ", i+1);
        scanf("%d", &cigla[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("Unesite potrosenu kolicinu crepa u komadima za %d. dan: ", i+1);
        scanf("%d", &crep[i]);
    }

    printf("Uneti cenu maltera po kilogramu: ");
    scanf("%f", &cena_maltera);

    printf("Uneti cenu cigle po komadu: ");
    scanf("%f", &cena_cigle);

    printf("Uneti cenu crepa po komadu: ");
    scanf("%f", &cena_crepa);

    for (int i = 0; i < n; i++) {
        float cigla_po_danu = cena_cigle * cigla[i];
        ukupno_cigle += cigla[i];
        ukupno += malter[i] * cena_maltera + cigla_po_danu + crep[i] * cena_crepa;
    }

    printf("Ukupno je potroseno %.2f novca za %d dana gradnje.\n", ukupno, n);

    printf("Prosecno je potroseno %.2f cigli po danu.\n", ukupno_cigle/n);

    max = crep[0] + cigla[0] + malter[0];
    maxIndex = 0;

    for (int i = 1; i < n; i++) {
        int potencilani_max = crep[i] + cigla[i] + malter[i];
        if (potencilani_max > max) {
            max = potencilani_max;
            maxIndex = i;
        }
    }

    printf("Najvise je potroseno %.2f materijala %d. dana.\n", max, maxIndex + 1);

    return 0;
}

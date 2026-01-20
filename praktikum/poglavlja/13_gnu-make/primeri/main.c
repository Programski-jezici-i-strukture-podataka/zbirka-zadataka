#include <stdio.h>

#include "pravougaonik.h"
#include "kvadrat.h"

int main()
{
    printf("Povrsina pravougaonika: %.1lf\n", povrsina_pravougaonika(2.0, 3.0));
    printf("Povrsina kvadrata: %.1lf\n", povrsina_kvadrata(2.0));

    return 0;
}
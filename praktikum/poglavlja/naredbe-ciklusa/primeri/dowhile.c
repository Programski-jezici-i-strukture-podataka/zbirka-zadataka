#include <stdio.h>

int main() {
    int n;

    do {
        printf("Uneti prirodan broj: ");
        scanf("%d",&n);
    } while(n <= 0);

    printf("Uspesno unet prirodan broj.\n");
}


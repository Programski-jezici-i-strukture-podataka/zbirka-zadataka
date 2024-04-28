#include <stdio.h>

#define MASK 0x8000

void print_binary(short);

int main() 
{
    short dec;
    printf("Unesite broj: ");
    scanf("%hd", &dec);
    print_binary(dec);
    return 0;
}

void print_binary(short dec) 
{
    int i;
    for(i = 1; i <= sizeof(short) * 8; i++) 
    {
        printf("%d", (dec & MASK) != 0);
        dec <<= 1;
        if(i % 4 == 0) 
        {
            printf(" ");
        }
    }
    printf("\n");
}

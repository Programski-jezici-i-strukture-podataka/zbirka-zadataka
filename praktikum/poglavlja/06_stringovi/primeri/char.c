#include <stdio.h>
#include <stdio_ext.h>

int main()
{
    char slovo;
    
    do 
    {
      printf("Uneti malo slovo: ");
      scanf("%c", &slovo);
      __fpurge(stdin);
    } while(slovo < 'a' || slovo > 'z');
    
    printf("Veliko slovo je: %c\n", slovo - 32);
    return 0;
}

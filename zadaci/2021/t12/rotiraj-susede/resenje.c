#include <stdio.h>
#include <string.h>

#define MAX_STRING 21+1

int main()
{
    char str[MAX_STRING],izmenjen[MAX_STRING],znak;
    int n,i,j,indIzmenjen=0,paran=0,brIzbacenih=0;
    
    do
    {
        printf("Unesite zeljeni string (max duzine %d):",MAX_STRING-1);
        gets(str);
    }while(strlen(str)<=0 || strlen(str)>MAX_STRING);
    
        
    printf("Uneti znak koji zelite da izbacite:");
    scanf("%c",&znak);

    for(i=0;i<strlen(str);i++)
    {
        if(str[i]!=znak)
        {   
            izmenjen[indIzmenjen] = str[i];
            indIzmenjen++;
        }else
            brIzbacenih++;
    }
    izmenjen[indIzmenjen]='\0';

    if(strlen(izmenjen)%2!=0)
        paran=1;

    char temp;
    for(i=0,j=i+1;i<strlen(izmenjen)-paran;i+=2,j+=2)
    {
        temp=izmenjen[i];
        izmenjen[i]=izmenjen[j];
        izmenjen[j]=temp;
    }

    printf("\tKarakter %c je iz polaznog stringa izbacen %d puta.\n",znak,brIzbacenih);
    printf("\tString nakon modifikacija: %s\n",izmenjen);


    return 0;

}


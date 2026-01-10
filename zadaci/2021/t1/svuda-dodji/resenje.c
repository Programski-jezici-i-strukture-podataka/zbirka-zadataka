#include <stdio.h>
#include <string.h>

#define MAX_STRING 22+1

int main()
{
    char str[MAX_STRING],prvi[MAX_STRING],poslednji[MAX_STRING];
    int n,i,indPrvi=0,indPoslednji=0;

    do
    {
        printf("Unesite zeljeni string (max duzine %d):",MAX_STRING-1);
        gets(str);
    } while(strlen(str)<=0 || strlen(str)>MAX_STRING);

    for(i=0;i<strlen(str);i++)
    {
        if(str[i]==' ')
        {
            break;
        }else
        {
            if(str[i]>='a' && str[i]<='z')
                prvi[indPrvi] = str[i]-32;
            else
                prvi[indPrvi] = str[i];

            indPrvi++;
        }
    }
    prvi[indPrvi]='\0';
    
    int index;
    for(i=strlen(str);i>=0;i--)
    {
        if(str[i]==' ')
        {
            index = ++i;
            break;      
        }
    }

    for(i=index;i<strlen(str);i++)
    {
        if(str[i]>='a' && str[i]<='z')
            poslednji[indPoslednji] = str[i]-32;
        else
            poslednji[indPoslednji] = str[i];
        
        indPoslednji++;                 
    }
    poslednji[indPoslednji] = '\0';

    strcat(prvi," ");
    puts(strcat(prvi,poslednji));
    
    return 0;
}


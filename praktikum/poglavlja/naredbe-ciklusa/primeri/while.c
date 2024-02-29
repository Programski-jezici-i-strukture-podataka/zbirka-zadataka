#include <stdio.h>

int main()
{
    int p,q,r=0;

    printf("Unesite deljenik i delilac!\n");
    scanf("%d %d",&p,&q);

    while(p >= q) 
    {
        p -= q;
        r++;
    }
    printf("kolicnik je %d, a ostatak %d\n", r,p);

    return 0;
}

#include <stdio.h>
#include <math.h>
#define MAX_SIZE 25

int main(){

    double M[MAX_SIZE], K[MAX_SIZE];
    double maxPovrsina, a;
    int n, i, maxIndex, brojVecih=0;
    
    do{
        printf("Unesite broj elemenata niza M (broj elemenata ne sme da prelazi 25): ");
        scanf("%d", &n);
    }while(n<0 || n>MAX_SIZE);
    
    printf("\nUnesite elemente niza M:\n");
    for(i=0; i<n; i++){
    	do{
    	    printf("M[%d]=",i);
    	    scanf("%lf", &M[i]);
    	}while(M[i]<0);	
    }
    
    for(i=0; i<n; i++){
    	K[i]=pow(M[i], 2);
    }
    
    maxPovrsina = K[0];
    maxIndex = 0;
    
    for(i=1; i<n; i++){
    	if(K[i]>maxPovrsina){
    		maxPovrsina=K[i];
    		maxIndex=i;
        }
    }
    
    if(maxIndex%2==0){
        printf("Povrsina najveceg kruga iznosi %.2lf, nalazi se na %d indeksu.\n", maxPovrsina, maxIndex);}
    else{
        printf("Povrsina najveceg kruga iznosi %.3lf, nalazi se na %d indeksu.\n", maxPovrsina, maxIndex);
    }
    
    do{
        printf("Unesite realan pozitivan broj a:");
        scanf("%lf", &a);
    }while(a<0);
    
    for(i=0; i<n; i++){
    	if(M[i]>a) brojVecih++;
    }
    
    printf("\nBroj vecih poluprecnika od %.1lf je %d.\n", a, brojVecih);
    
    printf("\nM=[");
    for(i=0; i<n; i++){
    	if(i>0){
    		printf(", ");
    	}
    	printf("%.2lf", M[i]);
    }
    printf("]\n");
    
    printf("K=[");
    for(i=0; i<n; i++){
    	if(i>0){
    		printf(", ");
    	}
    	printf("%.2lf", K[i]);
    }
    printf("]\n");
    
    return 0;
}

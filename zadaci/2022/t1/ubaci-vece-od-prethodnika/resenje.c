#include <stdio.h>
#define MAX_SIZE 30

int main(){
	int M[MAX_SIZE], A[MAX_SIZE], B[MAX_SIZE];
	int n, i, brElA=0, brElB=0, sumaSvih =0;
	double srVrednost;

	do{
printf("Unesite broj elemenata niza M (broj elemenata ne sme da prelazi 30): ");
scanf("%d", &n);
}while(n<0 || n>MAX_SIZE);

printf("\nUnesite elemente niza:\n");
for(i=0; i<n; i++){
	printf("M[%d]=",i);
	scanf("%d", &M[i]);
}

for(i=1; i<n; i++){
	if(M[i]>M[i-1]){
		A[brElA]=M[i];
		brElA++;
	}
}

for(i=0; i<n; i++){
	sumaSvih+=M[i];
}

srVrednost=(double)sumaSvih/n;

for(i=0; i<n; i++){
	if(M[i]>srVrednost){
		B[brElB]=M[i];
		brElB++;
	}
}

printf("\nA=[");
for(i=0; i<brElA; i++){
	if(i>0){
		printf(", ");
	}
	printf("%d", A[i]);
}
printf("]\n");

printf("B=[");
for(i=0; i<brElB; i++){
	if(i>0){
		printf(", ");
	}
	printf("%d", B[i]);
}
printf("]\n\n");

printf("Srednja vrednost niza M je: %.3lf\n", srVrednost);

return 0;

}

#include<stdio.h>
#define MAX 10

int main(){
	int num[MAX], i, j, k, tmp;

	for(i=0; i<MAX; i++)
		scanf("%d", &num[i]);

	for(j=0; j<MAX; j++){
		for(k=0; k<MAX-j-1; k++){
			if(num[k]>num[k+1]){
				tmp = num[k];
				num[k] = num[k+1];
				num[k+1] = tmp;
			}
		}
	}
	for(i=0; i<MAX; i++){
		printf("%d ", num[i]);
	}
}

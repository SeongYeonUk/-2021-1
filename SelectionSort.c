#include<stdio.h>
#define MAX 10

int main(){

	int num[MAX], i, j, k, min, tmp;

	for(i=0; i<MAX; i++)
		scanf("%d", &num[i]);

	for(j=0; j<i-1; j++){
		min = j;
		for(k = j+1; k<i; k++)
			if(num[k]<num[min])
				min = k;
		if(j != min){
			tmp = num[min];
			num[min] = num[j];
			num[j] = tmp;
		
	}

	for(j=0; j<i; j++)
		printf("%d ", num[j]);
}

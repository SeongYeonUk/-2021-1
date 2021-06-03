#include<stdio.h>
#define MAX_INDEX 30

void main(){
int i, j, num, tmp, numOfElem, min, intarr[MAX_INDEX];

numOfElem = 0;
while(scanf("%d", &num)!=EOF){
intarr[numOfElem] = num;
numOfElem++;
}
for(i=0; i<numOfElem -1; i++){
min = i;
for(j=i+1; j<numOfElem; j++)
if(intarr[j] < intarr[min]) min = j;
if(i!=min){
tmp = intarr[i];
intarr[i] = intarr[min];
intarr[min] = tmp;
}
}
for(i=0; i<numOfElem; i++) printf("%d ", intarr[i]);
printf("\n");
}

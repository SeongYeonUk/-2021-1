#include<stdio.h>
#pragma warning (disable :4996)
#define MAX 100

int main() {
	int num[MAX];
	int cnt = 0, i;
	int max, min, sum =0, avg;
	
	while (scanf("%d", &num[cnt++]) != EOF);

	max = min = num[0];
	cnt -= 1;

	for (i = 0; i < cnt; i++) {
		if (num[i] > max)
			max = num[i];
		if (num[i] < min)
			min = num[i];
		sum += num[i];
	}
	avg = sum / cnt;

	printf("최대값 : %d\n", max);
	printf("최소값 : %d\n", min);
	printf("합계 : %d\n", sum);
	printf("평균 : %d\n", avg);
}

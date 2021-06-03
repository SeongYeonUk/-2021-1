#include<stdio.h>
#pragma warning(disable : 4996)

int n, i;
int Fibo(int n);

int main(void) {
	scanf("%d", &n);
	
	printf("%d번째 Fibonacci number : %d\n", n, Fibo(n));
	
	return 0;
}

int Fibo(int n) {
	if (n < 2) return n;
	else return Fibo(n - 1) + Fibo(n - 2);
}

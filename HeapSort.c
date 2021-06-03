#include<stdio.h>
#pragma warning (disable : 4996)
#define MAX 10

void HeapSort(int*, int);
void heapify(int*, int, int);

int main() {

    int num[MAX], i, j, k, min, tmp;

    for (i = 0; i < MAX; i++)
        scanf("%d", &num[i]);

	HeapSort(num, MAX);

	printf("\nAfter sorting >> ");
	for (i = 0; i < MAX; i++)
		printf("%d ", num[i]);

}

void HeapSort(int* A, int n) {
	int i;
	for (i = (n - 1) / 2; i >= 0; i--)
		heapify(A, i, n);
	for (i = n - 1; i >= 0; i--) {
		int tmp = A[0];
		A[0] = A[i];
		A[i] = tmp;
		heapify(A, 0, i);
	}
}
void heapify(int* A, int i, int n) {
	int ai = A[i];
	while (i < n / 2) {
		int j = 2 * i + 1;
		if (j + 1 < n)
			if (A[j + 1] > A[j])
				j++;
		if (A[j] <= ai)
			break;
		A[i] = A[j];
		i = j;
	}
	A[i] = ai;
}


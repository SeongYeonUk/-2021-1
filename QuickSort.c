#include<stdio.h>
#pragma warning (disable : 4996)
#define MAX 10

void QuickSort(int*, int, int);
int Split(int*, int, int);


int main() {

    int num[MAX], i, j, k, min, tmp;

    for (i = 0; i < MAX; i++)
        scanf("%d", &num[i]);

	QuickSort(num, 0, MAX - 1);

	printf("\nAfter Sorting >> ");
	for (i = 0; i < MAX; i++)
		printf("%d ", num[i]);
}

void QuickSort(int* A, int start, int end) {
	int idx;
	if (start < end) {
		idx = Split(A, start, end);
		QuickSort(A, start, idx - 1);
		QuickSort(A, idx + 1, end);
	}
}

int Split(int* A, int start, int end) {
	int pivot = A[start], left = start + 1, right = end;
	while (left <= right) {
		while (A[left] <= pivot && left <= right)
			left++;
		while (A[right] >= pivot && left <= right)
			right--;
		if (left < right) {
			int tmp = A[left];
			A[left] = A[right];
			A[right] = tmp;
		}
	}
	if (start != right) {
		A[start] = A[right];
		A[right] = pivot;
	}
	return right;
}

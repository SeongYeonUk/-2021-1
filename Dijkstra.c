#include<stdio.h>
#pragma warning(disable : 4996)
#define max 5
#define INF 1000
#define TRUE 1
#define FALSE 0

int arr[max][max] = {
	{0, 7, INF, INF, 3,},
	{7, 0, 4, 10, 2,},
	{INF, 4, 0, 2, INF},
	{INF, 10, 2, 0 ,11},
	{3, 2, INF, 11, 0}
};

int d[max];
int v[max];

int Shortest();
void dijkstra(int);

int main() {
	int i;

	dijkstra(0);
	for (i = 0; i < max; i++) {
		printf("%d ", d[i]);
	}

}

int Shortest() {
	int min = INF;
	int index = 0;
	int i;
	for (i = 0; i < max; i++) {
		if (d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	int i, j;
	for (i = 0; i < max; i++) {
		d[i] = arr[start][i];
	}
	v[start] = TRUE;
	for (i = 0; i < max - 1; i++) {
		int cur = Shortest();
		v[cur] = TRUE;
		for (j = 0; j < max; j++) {
			if (!v[j]) {
				if (d[cur] + arr[cur][j] < d[j]) {
					d[j] = d[cur] + arr[cur][j];
				}
			}
		}
	}
}

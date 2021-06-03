#include<stdio.h>
#define N 10
int main() {
int j, i, k, l, key;
int a[N] = { 0 };for(k=0; k<N; k++)
scanf( "%d", &a[k] );
for (j = 1; j < N; j++) {
key = a[j];
i = j - 1;
while (i >= 0 && a[i] > key) {
a[i + 1] = a[i];
i--;
}
a[i + 1] = key;
}
for (l = 0; l < N; l++)
printf("%d ", a[l]);
}

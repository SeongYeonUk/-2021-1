#include<stdio.h>
#pragma warning(disable:4996)
#define max 100

int stack[max], TOP = -1;

void push(int);
int pop();

int main() {
	char pfs[max];
	fgets(pfs, max, stdin);
	int len;
	for (len = 0; pfs[len] != '\0'; len++);

	int i, n, e, j, k, l;
	for (i = 0; i < len; i++) {
		n = 0;
		e = 0;
		if (pfs[i] == ' ' || pfs[i] == '\n')
			continue;
		else if ('0' <= pfs[i] && pfs[i] <= '9') {
			l = 1;
			while ('0' <= pfs[i] && pfs[i] <= '9') {
				e++;
				i++;
			}
			i--;
			k = i;
			for (j = 0; j < e; j++) {
				n += (pfs[k--] - 48) * l;
				l *= 10;
			}
			push(n);
		}
		else {
			int n1, n2;
			switch (pfs[i]) {
			case'+':
				n2 = pop();
				n1 = pop();
				push(n1 + n2);
				break;
			case'-':
				n2 = pop();
				n1 = pop();
				push(n1 - n2);
				break;
			case'*':
				n2 = pop();
				n1 = pop();
				push(n1 * n2);
				break;
			case'/':
				n2 = pop();
				n1 = pop();
				push(n1 / n2);
				break;
			}
		}
	}
	printf("%d", pop());
}

void push(int x) {
	stack[++TOP] = x;
}
int pop() {
	return stack[TOP--];
}


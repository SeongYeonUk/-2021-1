#include<stdio.h>
#pragma warning(disable:4996)
#define max 100

char stack[max];
int TOP = -1;

void push(char);
char pop();
int isEmpty();

int isp(char);
int icp(char);

int main() {
	char ifs[max];
	fgets(ifs, max, stdin);
	int len;
	for (len = 0; ifs[len] != '\0'; len++);

	int i;
	for (i = 0; i < len; i++) {
		if (ifs[i] == ' ' || ifs[i] == '\n')
			continue;
		else if ('0' <= ifs[i] && ifs[i] <= '9') {
			while ('0' <= ifs[i] && ifs[i] <= '9') {
				printf("%c", ifs[i++]);
			}
			i--;
			printf(" ");
		}
		else if (ifs[i] == ')') {
			while (stack[TOP] != '(') {
				printf("%c ", pop());
			}
			pop();
		}
		else {
			if (isEmpty())
				push(ifs[i]);
			else {
				while (!isEmpty() && isp(stack[TOP]) >= icp(ifs[i]))
					printf("%c ", pop());
				push(ifs[i]);
			}
		}
	}
	while (!isEmpty())
		printf("%c ", pop());
}

void push(char x) {
	stack[++TOP] = x;
}
char pop() {
	return stack[TOP--];
}
int isEmpty() {
	if (TOP == -1)
		return 1;
	else
		return 0;
}

int isp(char x) {
	switch (x) {
	case'(':
		return 0;
		break;
	case'+':
	case'-':
		return 1;
		break;
	case'*':
	case'/':
		return 2;
		break;

	}
}
int icp(char x) {
	switch (x) {
	case'(':
		return 3;
		break;
	case'+':
	case'-':
		return 1;
		break;
	case'*':
	case'/':
		return 2;
		break;
	}
}

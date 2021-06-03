#include<stdio.h>
#include<stdlib.h>
#pragma warning ( disable : 4996 )
#define max 100

int main() {

	struct list {
		int num;
		struct list* next;
	};

	struct list* first, * cur, * pre, * newrec, * contents;

	FILE* in = fopen("data.txt", "r");
	first = pre = NULL;
	while (1) {
		newrec = malloc(sizeof(max));
		if (fscanf(in, "%d", newrec) == EOF)
			break;
		newrec->next = NULL;

		if (first == NULL)
			first = newrec;
		else {
			cur = first;
			while (newrec->num > cur->num) {
				pre = cur;
				cur = cur->next;
				if (cur == NULL)
					break;
			}
			if (cur == first) {
				newrec->next = first;
				first = newrec;
			}
			else {
				pre->next = newrec;
				newrec->next = cur;
			}
		}
	}
	contents = first;
	while (contents != NULL) {
		printf("%d\n", contents->num);
		contents = contents->next;
	}
}

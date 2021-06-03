#include<stdio.h>
#include<string.h>
#pragma warning (disable : 4996)
#define MAX 100

int main(int argc, char** argv) {

	FILE* in[MAX];
	char cxt;
	int i;

	if (strcmp(argv[1], "-l") != 0 && strcmp(argv[1], "-w") != 0
		&& strcmp(argv[1], "-c") != 0 && strcmp(argv[1], "-lw") != 0
		&& strcmp(argv[1], "-lc") != 0 && strcmp(argv[1], "-wc") != 0
		&& strcmp(argv[1], "-lwc") != 0) {

		for (i = 0; i < argc - 1; i++) {
			in[i] = fopen(argv[i + 1], "r");
			int LineCnt = 0, WordCnt = 0, CharCnt = 0;

			while (fscanf(in[i], "%c", &cxt) != EOF) {
				if (cxt == '\n')
					LineCnt++;
				if (cxt == ' ')
					WordCnt++;
				CharCnt++;
			}
			LineCnt++;
			WordCnt++;
			printf("Line : %d Word : %d Char : %d\n\n", LineCnt, WordCnt, CharCnt);
		}
	}
	else if (strcmp(argv[1], "-l") == 0) {
		for (i = 0; i < argc - 1; i++) {
			in[i] = fopen(argv[i + 2], "r");
			int LineCnt = 0, WordCnt = 0, CharCnt = 0;

			while (fscanf(in[i], "%c", &cxt) != EOF) {
				if (cxt == '\n')
					LineCnt++;
			}
			LineCnt++;
			printf("Line : %d\n\n", LineCnt);
		}
	}
	else if (strcmp(argv[1], "-w") == 0) {
		for (i = 0; i < argc - 1; i++) {
			in[i] = fopen(argv[i + 2], "r");
			int LineCnt = 0, WordCnt = 0, CharCnt = 0;

			while (fscanf(in[i], "%c", &cxt) != EOF) {
				if (cxt == ' ')
					WordCnt++;
			}
			WordCnt++;
			printf("Word : %d\n\n", WordCnt);
		}
	}
	else if (strcmp(argv[1], "-c") == 0) {
		for (i = 0; i < argc - 1; i++) {
			in[i] = fopen(argv[i + 2], "r");
			int LineCnt = 0, WordCnt = 0, CharCnt = 0;

			while (fscanf(in[i], "%c", &cxt) != EOF) {
					CharCnt++;
			}
			printf("Char : %d\n\n", CharCnt);
		}
	}
	else if (strcmp(argv[1], "-lw") == 0) {
		for (i = 0; i < argc - 1; i++) {
			in[i] = fopen(argv[i + 2], "r");
			int LineCnt = 0, WordCnt = 0, CharCnt = 0;

			while (fscanf(in[i], "%c", &cxt) != EOF) {
				if (cxt == '\n')
					LineCnt++;
				if (cxt == ' ')
					WordCnt++;
			}
			LineCnt++;
			WordCnt++;
			printf("Line : %d Word : %d\n\n", LineCnt, WordCnt);
		}
	}
	else if (strcmp(argv[1], "-lc") == 0) {
		for (i = 0; i < argc - 1; i++) {
			in[i] = fopen(argv[i + 2], "r");
			int LineCnt = 0, WordCnt = 0, CharCnt = 0;

			while (fscanf(in[i], "%c", &cxt) != EOF) {
				if (cxt == '\n')
					LineCnt++;
				CharCnt++;
			}
			LineCnt++;
			printf("Line : %d Char : %d\n\n", LineCnt, CharCnt);
		}
	}
	else if (strcmp(argv[1], "-wc") == 0) {
		for (i = 0; i < argc - 1; i++) {
			in[i] = fopen(argv[i + 2], "r");
			int LineCnt = 0, WordCnt = 0, CharCnt = 0;

			while (fscanf(in[i], "%c", &cxt) != EOF) {
				if (cxt == ' ')
					WordCnt++;
				CharCnt++;
			}
			WordCnt++;
			printf("Word : %d Char : %d\n\n", WordCnt, CharCnt);
		}
	}
	else if (strcmp(argv[1], "-lwc") == 0) {
		for (i = 0; i < argc - 1; i++) {
			in[i] = fopen(argv[i + 2], "r");
			int LineCnt = 0, WordCnt = 0, CharCnt = 0;

			while (fscanf(in[i], "%c", &cxt) != EOF) {
				if (cxt == '\n')
					LineCnt++;
				if (cxt == ' ')
					WordCnt++;
				CharCnt++;
			}
			LineCnt++;
			WordCnt++;
			printf("Line : %d Word : %d Char : %d\n\n", LineCnt, WordCnt, CharCnt);
		}
	}
}


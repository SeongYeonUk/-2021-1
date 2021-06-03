#include<stdio.h>
#include<string.h>
#pragma warning(disable : 4996)
#define MAX 1000

int main(int argc, char* argv[]) {
    FILE* in[MAX], neo;
    int i, j = 1;
    if (argc == 1) {
        char cxt;
        while ((cxt = getchar()) != EOF)
            fprintf(stdout, "%c", cxt);
    }
    else if (strcmp(argv[1], "-n") == 0) {
        for (i = 2; i < argc; i++) {
            char cxt = '0';
            in[i] = fopen(argv[i], "r");
            
            if(i==2)
                printf("%d ", j);

            while (fscanf(in[i], "%c", &cxt) != EOF) {
                printf("%c", cxt);
                if (cxt == '\n')
                    printf("%d ", ++j);
            }
        }
       while (j != 0) {
            printf("\b \b");
            j /= 10;
        }
        printf("\b \b");
    }
    else {
        for (i = 1; i < argc; i++) {
            char cxt = '0';
            in[i] = fopen(argv[i], "r");

            while (fscanf(in[i], "%c", &cxt) != EOF)
                printf("%c", cxt);
        }
    }
}

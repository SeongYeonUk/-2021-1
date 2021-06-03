#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#pragma warning(disable : 4996)
#define MAX 1000

int main(int argc, char* argv[]) {
    FILE* in[MAX], * out;
    char ctx;
    struct stat buf;
    int i;

    if (argc == 3) {
        in[0] = fopen(argv[1], "r");
        in[1] = fopen(argv[2], "w");
        while (fscanf(in[0], "%c", &ctx) != EOF)
            fprintf(in[1], "%c", ctx);
    }
    else {
        lstat(argv[argc - 1], &buf);
        if (!S_ISDIR(buf.st_mode))
            printf("cp: target '%s' is not a directory\n", argv[argc - 1]);
        else {
            for (i = 1; i < argc - 1; i++) {
                in[i] = fopen(argv[i], "r");
                chdir(argv[argc - 1]);
                out = fopen(argv[i], "w");
		chdir("../");
                while (fscanf(in[i], "%c", &ctx) != EOF){
		    chdir(argv[argc - 1]);
                    fprintf(out, "%c", ctx);
		    chdir("../");
		}
            }
        }
    }
}

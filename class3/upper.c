#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TO_UPPERCASE ('A' - 'a')

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("usage: ./upper <text>\n");
        exit(1);
    } else {
        for (int n_args = 1; n_args < argc; n_args++) {
            char *arg = argv[n_args];
            size_t arg_len = strlen(arg);
            for (int j = 0; j < arg_len; j++) {
                if ((arg[j] >= 97) && (arg[j] <= 122)) {
                    arg[j] = arg[j] + TO_UPPERCASE;
                }
                printf("%c", arg[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
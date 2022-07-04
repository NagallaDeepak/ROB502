#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getParity(const char* arg) {
    int parity = 0;
    size_t len = strlen(arg);
    for (int j = 0; j < len; j++) {
        unsigned int u_arg = arg[j];
        while (u_arg) {
            parity =  !parity;
            u_arg = u_arg & (u_arg - 1);
        }
    }
    return parity;
}

int main(int argc, char** argv) {
    if (argc > 2) {
        printf("usage: ./parity [<text>]\n");
        exit(1);
    } else {
        int parity = 0;
        for (int n_args = 1; n_args < argc; n_args++) {
            char *arg = argv[n_args];
            parity = getParity(arg);
        }
        printf("%d\n", parity);
    }
    return 0;
}
#include <stdlib.h>
#include <stdio.h>

#define N_TRITS 243
char *trit_encodings[N_TRITS];
const char colors[] = {' ', ':', '@'};

int main(void) {
    // at the very beginning of your program, making the table
    for (int i = 0; i < N_TRITS; i++) {
        trit_encodings[i] = calloc(sizeof(char), 6);

        // Initialize the array to "     \0" => "00000\0"
        for (int j = 0; j < 5; j++) {
            trit_encodings[i][j] = ' ';
        }
        trit_encodings[i][5] = '\0';

        // Use the basic logic of converting from decimal to nth index
        // In this case, convert to index 3
        // Divide the given index by 3 and put the remainder in array
        // Repeat this until the number is 0
        int n = i, j=0;
        while (n > 0) {
            trit_encodings[i][j] = colors[n%3];
            n = n/3;
            j++;
        }
    }

    FILE *file = fopen("img.bin", "rb");

    // check if the bin file exists.
    if (!file) {
        printf("Unable to open file\n");
        return 1;
    }

    // Iterate through all the rows and characters in each row
    // Extract each byte using fgetc and print corresponding trit
    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 18; j++) {
            int c = fgetc(file);
            if (c >= 0) {
                printf("%s", trit_encodings[c]); // use %s with printf to print strings
            }
        }
        printf("\n");
    }

    // at the very end of your program, cleaning up memory
    for (int i = 0; i < N_TRITS; i++) {
        free(trit_encodings[i]);
    }
    return 0;
}
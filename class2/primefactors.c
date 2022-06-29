// This program prints the primefactors of the number provided by user
// Assues the user inputs a positive integer
// The repetition of prime factors is printed

#include <stdio.h>

void primeFactors(int input) {
    for (int factor=2; input > 1; factor++) {
        while (input%factor == 0) {
            printf("%d\n", factor);
            input /= factor;
        }
    }
}

int main(void) {
    int input;
    printf("Enter a number:");
    scanf("%d", &input);

    primeFactors(input);

    return 0;
}

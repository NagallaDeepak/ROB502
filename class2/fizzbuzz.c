// This program prints the numbers from 1 to 100
// If a number is divisible by 3, fizz is printed
// instead of the actual number.
// buzz is printed instead of numbers divisible by 5
// In place of numbers divisible by 3 and 5, fizzbuzz is printed

#include <stdio.h>
int main(void) {
    for (int i=1; i<=100; i++) {
        if ((i%3 == 0) && (i%5 == 0)) {
            printf("fizzbuzz\n");
        } else {
            if (i%3 == 0) {
                printf("fizz\n");
            } else if (i%5 == 0) {
                printf("buzz\n");
            } else {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}

#include <stdio.h>

int main() {
    int num, reversed = 0, remainder;

    printf("Enter a number: ");
    scanf("%d", &num);

    int original = num; // store original number

    // Reverse the number
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num = num / 10;
    }

    printf("Reversed number: %d\n", reversed);

    // Add 10 to reversed number
    reversed += 10;

    printf("Result after adding 10: %d\n", reversed);

    return 0;
}

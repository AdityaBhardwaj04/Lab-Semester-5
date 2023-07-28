#include <stdio.h>

int main() {
    unsigned int num;
    unsigned char bytes[4];

    printf("Enter a number: ");
    scanf("%u", &num);

    // Extract each byte from the number
    for (int i = 0; i < 4; i++) {
        bytes[i] = (num >> (i * 8)) & 0xFF;
    }

    // Print the content of each byte
    for (int i = 0; i < 4; i++) {
        printf("Byte %d: %u\n", i, bytes[i]);
    }

    return 0;
}
    
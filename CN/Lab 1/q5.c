#include <stdio.h>

int main() {
    unsigned int num = 1;
    char *c = (char*)&num;

    // Check whether the host machine is in Little Endian or Big Endian
    if (*c) {
        printf("Little Endian\n");
    } else {
        printf("Big Endian\n");
    }

    // Enter a number
    printf("Enter a number: ");
    scanf("%u", &num);

    // Print the content of each byte location
    printf("Byte 0: %u\n", (num >> 0) & 0xFF);
    printf("Byte 1: %u\n", (num >> 8) & 0xFF);
    printf("Byte 2: %u\n", (num >> 16) & 0xFF);
    printf("Byte 3: %u\n", (num >> 24) & 0xFF);

    // Convert the Endianness of the same
    num = ((num >> 24) & 0x000000FF) |
          ((num >> 8) & 0x0000FF00) |
          ((num << 8) & 0x00FF0000) |
          ((num << 24) & 0xFF000000);

    // Print the content of each byte location after converting the Endianness
    printf("After converting Endianness:\n");
    printf("Byte 0: %u\n", (num >> 0) & 0xFF);
    printf("Byte 1: %u\n", (num >> 8) & 0xFF);
    printf("Byte 2: %u\n", (num >> 16) & 0xFF);
    printf("Byte 3: %u\n", (num >> 24) & 0xFF);

    return 0;
}

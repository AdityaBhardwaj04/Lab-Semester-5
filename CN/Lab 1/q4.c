#include <stdio.h>

struct pkt {
    char ch1;
    char ch2[2];
    char ch3;
};

int main() {
    int num;
    struct pkt p;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Store the number across the members of the structure
    p.ch1 = (num >> 24) & 0xFF;
    p.ch2[0] = (num >> 16) & 0xFF;
    p.ch2[1] = (num >> 8) & 0xFF;
    p.ch3 = num & 0xFF;

    // Print the content of each member of the structure
    printf("ch1: %d\n", p.ch1);
    printf("ch2[0]: %d\n", p.ch2[0]);
    printf("ch2[1]: %d\n", p.ch2[1]);
    printf("ch3: %d\n", p.ch3);

    // Aggregate each member of the structure to form the original number
    int original_num = (p.ch1 << 24) | (p.ch2[0] << 16) | (p.ch2[1] << 8) | p.ch3;

    // Print the original number
    printf("Original number: %d\n", original_num);

    return 0;
}

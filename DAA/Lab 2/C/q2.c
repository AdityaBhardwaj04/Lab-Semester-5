#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *fin = fopen(input_file, "r");
    if (fin == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    FILE *fout = fopen(output_file, "w");
    if (fout == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    int a, b;
    while (fscanf(fin, "%d%d", &a, &b) == 2)
        fprintf(fout, "The GCD of %d and %d is %d\n", a, b, gcd(a, b));

    fclose(fin);
    fclose(fout);

    fout = fopen(output_file, "r");
    if (fout == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    char c;
    while ((c = fgetc(fout)) != EOF)
        printf("%c", c);

    fclose(fout);

    return 0;
}

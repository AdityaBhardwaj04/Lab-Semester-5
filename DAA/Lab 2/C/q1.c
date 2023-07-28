#include <stdio.h>
#include <stdlib.h>

void decToBin(int n, FILE *fp) {
    if (n > 1) {
        decToBin(n / 2, fp);
    }
    fprintf(fp, "%d", n % 2);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <n> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    char *inputFile = argv[2];
    char *outputFile = argv[3];

    FILE *inFp = fopen(inputFile, "r");
    FILE *outFp = fopen(outputFile, "w");

    if (inFp == NULL || outFp == NULL) {
        printf("Error opening files\n");
        return 1;
    }

    int num;
    for (int i = 0; i < n && fscanf(inFp, "%d", &num) != EOF; i++) {
        fprintf(outFp, "The binary equivalent of %d is ", num);
        decToBin(num, outFp);
        fprintf(outFp, "\n");
    }

    fclose(inFp);
    fclose(outFp);

    outFp = fopen(outputFile, "r");
    if (outFp == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), outFp)) {
        printf("%s", line);
    }

    fclose(outFp);

    return 0;
}

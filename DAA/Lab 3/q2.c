#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(int arr[], int n, int *comparisons) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    char *input_file, *output_file;
    int choice;

    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");

    printf("Enter option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            input_file = "inAsce.dat";
            output_file = "outInsAsce.dat";
            break;
        case 2:
            input_file = "inDesc.dat";
            output_file = "outInsDesc.dat";
            break;
        case 3:
            input_file = "inRand.dat";
            output_file = "outInsRand.dat";
            break;
        default:
            printf("Invalid option\n");
            exit(1);
    }

    FILE *fin = fopen(input_file, "r");
    if (fin == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    int n = 0, num;
    while (fscanf(fin, "%d", &num) == 1)
        n++;

    rewind(fin);

    int arr[n], i = 0;
    while (fscanf(fin, "%d", &num) == 1)
        arr[i++] = num;

    fclose(fin);

    printf("Before Sorting: Content of the input file\n");
    printArray(arr, n);

    int comparisons = 0;
    insertionSort(arr, n, &comparisons);

    FILE *fout = fopen(output_file, "w");
    if (fout == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
        fprintf(fout, "%d ", arr[i]);

    fclose(fout);

    fout = fopen(output_file, "r");
    if (fout == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    char c;
    printf("After Sorting: Content of the output file\n");
    while ((c = fgetc(fout)) != EOF)
        printf("%c", c);
    printf("\nNumber of Comparisons: %d\n", comparisons);

    if (strcmp(input_file, "inAsce.dat") == 0 && comparisons == n - 1)
        printf("Scenario: Best-case\n");
    else if (strcmp(input_file, "inDesc.dat") == 0 && comparisons == n * (n - 1) / 2)
        printf("Scenario: Worst-case\n");
    else
        printf("Scenario: Average-case\n");

    fclose(fout);

    return 0;
}

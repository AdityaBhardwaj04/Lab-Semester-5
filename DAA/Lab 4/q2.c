#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int quick_sort(int* arr, int low, int high) {
    int comparisons = 0;
    if (low < high) {
        int pivot_index, pivot_comparisons;
        partition(arr, low, high, &pivot_index, &pivot_comparisons);
        comparisons += pivot_comparisons;
        int left_comparisons = quick_sort(arr, low, pivot_index - 1);
        int right_comparisons = quick_sort(arr, pivot_index + 1, high);
        comparisons += left_comparisons + right_comparisons;
    }
    return comparisons;
}

void partition(int* arr, int low, int high, int* pivot_index, int* comparisons) {
    int pivot = arr[high];
    int i = low - 1;
    *comparisons = 0;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        (*comparisons)++;
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    *pivot_index = i + 1;
}

int* read_file(char* file_name, int* n) {
    FILE* f = fopen(file_name, "r");
    int x;
    *n = 0;
    while (fscanf(f, "%d", &x) == 1) {
        (*n)++;
    }
    rewind(f);
    int* data = malloc(*n * sizeof(int));
    for (int i = 0; i < *n; i++) {
        fscanf(f, "%d", &data[i]);
    }
    fclose(f);
    return data;
}

void write_file(char* file_name, int* data, int n) {
    FILE* f = fopen(file_name, "w");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d ", data[i]);
    }
    fclose(f);
}

int main() {
    printf("MAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");

    int option;
    printf("Enter option: ");
    scanf("%d", &option);

    char input_file[20], output_file[20];

    if (option == 1) {
        strcpy(input_file, "inAsce.dat");
        strcpy(output_file, "outQuickAsce.dat");
    } else if (option == 2) {
        strcpy(input_file, "inDesc.dat");
        strcpy(output_file, "outQuickDesc.dat");
    } else if (option == 3) {
        strcpy(input_file, "inRand.dat");
        strcpy(output_file, "outQuickRand.dat");
    } else {
        printf("ERROR (EXIT)\n");
        return 0;
    }

    int n;
    int* data = read_file(input_file, &n);
    printf("Before Sorting: Content of the input file\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    int comparisons = quick_sort(data, 0, n - 1);

    write_file(output_file, data);

    printf("After Sorting: Content of the output file\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("Number of Comparisons: %d\n", comparisons);

    if (comparisons == n * (n - 1) / 2) {
        printf("Scenario: Worst-case\n");
    } else {
        printf("Scenario: Best-case\n");
    }

    free(data);

    return 0;
}

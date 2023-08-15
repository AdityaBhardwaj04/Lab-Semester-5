#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int merge_sort(int* arr, int n, char* order) {
    if (n > 1) {
        int mid = n / 2;
        int left_half[mid];
        memcpy(left_half, arr, mid * sizeof(int));
        int right_half[n - mid];
        memcpy(right_half, arr + mid, (n - mid) * sizeof(int));

        int left_comparisons = merge_sort(left_half, mid, order);
        int right_comparisons = merge_sort(right_half, n - mid, order);

        int i = 0, j = 0, k = 0;
        int comparisons = 0;

        while (i < mid && j < n - mid) {
            if ((strcmp(order, "asc") == 0 && left_half[i] < right_half[j]) || (strcmp(order, "desc") == 0 && left_half[i] > right_half[j])) {
                arr[k] = left_half[i];
                i++;
            } else {
                arr[k] = right_half[j];
                j++;
            }
            k++;
            comparisons++;
        }

        while (i < mid) {
            arr[k] = left_half[i];
            i++;
            k++;
        }

        while (j < n - mid) {
            arr[k] = right_half[j];
            j++;
            k++;
        }

        return left_comparisons + right_comparisons + comparisons;
    } else {
        return 0;
    }
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
    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. ERROR (EXIT)\n");

    int option;
    printf("Enter option: ");
    scanf("%d", &option);

    char input_file[20], output_file[20], order[5];

    if (option == 1) {
        strcpy(input_file, "inAsce.dat");
        strcpy(output_file, "outMergeAsce.dat");
        strcpy(order, "asc");
    } else if (option == 2) {
        strcpy(input_file, "inDesc.dat");
        strcpy(output_file, "outMergeDesc.dat");
        strcpy(order, "desc");
    } else if (option == 3) {
        strcpy(input_file, "inRand.dat");
        strcpy(output_file, "outMergeRand.dat");
        strcpy(order, "asc");
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

    clock_t start_time = clock();
    int comparisons = merge_sort(data, n, order);
    clock_t end_time = clock();

    write_file(output_file, data, n);

    printf("After Sorting: Content of the output file\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    printf("Number of Comparisons: %d\n", comparisons);
    printf("Execution Time: %ld nanoseconds\n", end_time - start_time);

    free(data);

    return 0;
}
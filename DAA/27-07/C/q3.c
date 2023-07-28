#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, count = 0, maxCount = 0, mostRepeating;
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);
    int arr[n];
    FILE *fp;
    fp = fopen("input1.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    fclose(fp);
    printf("The content of the array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break;
            }
        }
    }
    printf("\nTotal number of duplicate values = %d\n", count);
    for (i = 0; i < n; i++) {
        count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostRepeating = arr[i];
        }
    }
    printf("The most repeating element in the array = %d\n", mostRepeating);
    return 0;
}

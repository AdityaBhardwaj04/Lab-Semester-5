#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(int arr[], int n) {
  int i, j, key;

  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

int main() {
  int option, n, i, comparisons = 0;
  int arr[500];
  char filename[10];

  printf("MAIN MENU (INSERTION SORT)\n");
  printf("1. Ascending Data\n");
  printf("2. Descending Data\n");
  printf("3. Random Data\n");
  printf("4. ERROR (EXIT)\n");

  do {
    printf("Enter option: ");
    scanf("%d", &option);

    if (option == 1) {
      strcpy(filename, "inAsce.dat");
    } else if (option == 2) {
      strcpy(filename, "inDesc.dat");
    } else if (option == 3) {
      strcpy(filename, "inRand.dat");
    } else {
      break;
    }

    // Read data from input file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
      printf("Error opening file %s\n", filename);
      exit(1);
    }

    fscanf(fp, "%d", &n);
    for (i = 0; i < n; i++) {
      fscanf(fp, "%d", &arr[i]);
    }

    // Sort the data using insertion sort
    insertionSort(arr, n);

    // Print the sorted data to output file
    FILE *outfp = fopen("outIns" , "w");
    fprintf(outfp, "%d\n", n);
    for (i = 0; i < n; i++) {
      fprintf(outfp, "%d\n", arr[i]);
    }
    fclose(outfp);

    // Print the number of comparisons
    printf("Number of comparisons: %d\n", comparisons);

    // Check if the input scenario is best or worst case
    if (option == 1) {
      if (comparisons == 0) {
        printf("Scenario: Best Case\n");
      } else {
        printf("Scenario: Not Best Case\n");
      }
    } else if (option == 2) {
      if (comparisons == (n * (n - 1)) / 2) {
        printf("Scenario: Worst Case\n");
      } else {
        printf("Scenario: Not Worst Case\n");
      }
    } else {
      printf("Scenario: Not Applicable\n");
    }

    printf("\n");
  } while (option != 4);

  return 0;
}

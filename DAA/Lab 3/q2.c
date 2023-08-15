#include <stdio.h>
#include <stdlib.h>
void insertionSort(int arr[], int n){
	int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
}

int main(){

	char *input_file, *output_file;
	
	input_file = "input.dat";
	output_file = "output.dat";
	
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

    insertionSort(arr, n);

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
    printf("\nAfter Sorting: Content of the output file\n");
    while ((c = fgetc(fout)) != EOF)
        printf("%c", c);
    
    fclose(fout);
    return 0;
}

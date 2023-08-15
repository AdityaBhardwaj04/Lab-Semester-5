//best case scenario
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<time.h>
void insertionSort(int arr[], int n) {
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

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void RevprintArray(int arr[], int n) {
    for (int i = n-1; i > -1; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
	FILE *fp;
    double t;
	fp = fopen("Numbers.txt", "r");
	if(fp == NULL){
		printf("Error opening file \n");
		exit(1);
	}
	int n;
    printf("Enter number of elements you need:");
    scanf("%d",&n);
	int arr[n];
	for(int i = 0; i < n ; i++){
		fscanf(fp, "%d", &arr[i]);
	}
	fclose(fp);
    printf("Unsorted array: ");
    printArray(arr, n);
    clock_t t1=clock();
    printf("%d", t1);
	insertionSort(arr, n);
    printf("Sorted array: ");
    RevprintArray(arr, n);
    clock_t t2=clock();
    printf("\n%d", t2);
    t=(double)(t2-t1)/CLOCKS_PER_SEC;
    printf("\n%f", t);



}
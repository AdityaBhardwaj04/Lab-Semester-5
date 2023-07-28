#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n){
	int i, j;
	bool swapped;
	for(i = 0; i < n - 1; i++){
		swapped = false;
		for(j = 0; j < n - i - 1; j++){
			if(arr[j] > arr[j + 1]){
				swap(&arr[j], &arr[j+1]);
				swapped = true;
			}
		}
		
		if(swapped == false)
			break;
	}
}
int main(){
	FILE *fp;
	fp = fopen("input.txt", "r");
	if(fp == NULL){
		printf("Error opening file \n");
		exit(1);
	}
	int n;
	fscanf(fp, "%d", &n);
	int arr[n];
	for(int i = 0; i < n ; i++){
		fscanf(fp, "%d", &arr[i]);
	}
	fclose(fp);
	
	bubbleSort(arr, n);
	
	printf("Second Smallest Element: %d \n", arr[1]);
	printf("Second Largest Element: %d \n", arr[n - 2]);
	
	return 0;
}

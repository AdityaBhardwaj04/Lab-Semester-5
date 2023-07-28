#include <stdio.h>

int main(){
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i  <n; i++){
		printf("Enter data for element %d:", i);
		scanf("%d", &arr[i]);
	}
	int prefix[n];
	prefix[0] = arr[0];
	for(int i = 1; i < n; i++){
		prefix[i] = prefix[i - 1]  + arr[i];
	}
	
	for(int i = 0; i < n; i++){
		printf("%d ", prefix[i]);
	}
}

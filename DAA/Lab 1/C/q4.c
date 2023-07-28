#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Rotate_Right(int *p1, int p2){
    int i;
    for(i = p2 - 1; i > 0; i--){
        swap(&p1[i], &p1[i - 1]);
    }
}

int main(){
    int n;
    printf("ENTER THE SIZE OF ARRAY: ");
    scanf("%d", &n);

    int arr[n], p2;
    for(int i = 0; i < n; i++){
        printf("Enter data for index %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the index to rotate: ");
    scanf("%d", &p2);

    printf("Before ROTATE: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    Rotate_Right(arr, p2);

    printf("After ROTATE: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

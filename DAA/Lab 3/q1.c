#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x, int *comparisons) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        (*comparisons)++;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return binarySearch(arr, mid + 1, r, x, comparisons);
        else
            return binarySearch(arr, l, mid - 1, x, comparisons);
    }
    return -1;
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of the array: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int x;
    printf("Enter the key to be searched: ");
    scanf("%d", &x);

    int comparisons = 0;
    int result = binarySearch(arr, 0, n - 1, x, &comparisons);

    if (result == -1)
        printf("%d not found\n", x);
    else
        printf("%d found at index position %d\n", x, result);

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}

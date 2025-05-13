#include <stdio.h>

void insert(int arr[], int n) {
    int key = arr[n];
    int j = n - 1;

    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}

void insertionSortRecursive(int arr[], int n) {
    if (n <= 1) {
        return;
    }

    insertionSortRecursive(arr, n - 1);
    insert(arr, n - 1);
}

void printArray(int arr[], int size) {
	int i;
    for ( i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    insertionSortRecursive(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

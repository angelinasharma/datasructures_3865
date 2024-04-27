#include <stdio.h>

void bubbleSort(int arr[], int size) {
    int temp;
    for (int x = 0; x < size - 1; x++) {
        for (int y = 0; y < size - x - 1; y++) {
            if (arr[y] > arr[y + 1]) {
                temp = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;

    printf("How many elements do you want in the array?");
    scanf("%d", &size);

    int a[size];

    printf("Enter the integer elements for the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    printf("Entered elements in the first array: ");
    printArray(a, size);

    printf("\nSorting the array:\n");
    bubbleSort(a, size);

    printf("Array after sorting: ");
    printArray(a, size);


    return 0;
}

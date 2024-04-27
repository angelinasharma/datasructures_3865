#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;

        // Find the minimum element in the unsorted part of the array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Swap the found minimum element with the first element
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int size;
    printf("How many elements do you want in the array?");
    scanf("%d", &size);

    int a[size];

    for (int i = 0; i < size; i++) {
        printf("Enter the integer elements for the array: ");
        scanf("%d", &a[i]);
    }

    printf("Entered elements in the array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    // Call the selection sort function
    selectionSort(a, size);

    printf("\n\nArray after implementing Selection Sort: ");
    for (int x = 0; x < size; x++) {
        printf("%d  ", a[x]);
    }

    return 0;
}

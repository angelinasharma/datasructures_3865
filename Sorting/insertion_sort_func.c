#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    printf("\n\nSorting the array using Insertion Sort...\n");
    insertionSort(a, size);

    printf("\nArray after implementing Insertion Sort: ");
    for (int x = 0; x < size; x++) {
        printf("%d  ", a[x]);
    }

    return 0;
}

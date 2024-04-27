#include <stdio.h>

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

    // Insertion sort algorithm
    for (int i = 1; i < size; i++) {
        int key = a[i];
        int j = i - 1;

        // Move elements of a[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }

    printf("\n\nArray after implementing Insertion Sort: ");
    for (int x = 0; x < size; x++) {
        printf("%d  ", a[x]);
    }

    return 0;
}

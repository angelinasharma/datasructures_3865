#include <stdio.h>

int main() {
    int size, temp, swap_count, not_swap_count;
    printf("How many elements do you want in the array?");
    scanf("%d", &size);

    int a[size];
    int b[size];

    for (int i = 0; i < size; i++) 
    {
        printf("Enter the integer elements for the first array: ");
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < size; i++) 
    {
        printf("Enter the integer elements for the second array: ");
        scanf("%d", &b[i]);
    }

    printf("Entered elements in the first array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    
    printf("\nEntered elements in the second array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", b[i]);
    }
    
    // sorting for the first array
    printf("\nFor the first array: \n");
    for (int x = 0; x < size - 1; x++)
    {       
        printf("Iteration %d:\n", x + 1);

        for (int y = 0; y < size - x - 1; y++)
        {          
            if (a[y] > a[y + 1])
            {               
                temp = a[y];
                a[y] = a[y + 1];
                a[y + 1] = temp;
                
                printf("Swapping: %d and %d\n", a[y], a[y + 1]);
                swap_count += 1;
                printf("\n%d", swap_count);
            }
            else
            {
                printf("Not swapping: %d and %d\n", a[y], a[y + 1]);
                not_swap_count += 1;
                printf("\n%d", not_swap_count);
            }
        }
        
        printf("Array after iteration %d: ", x + 1);
        for (int z = 0; z < size; z++)
        {
            printf("%d ", a[z]);
        }
        printf("\n\n");
    }
    
    // sorting for the second array
    printf("\nFor the second array: \n");
    for (int x = 0; x < size - 1; x++)
    {       
        printf("Iteration %d:\n", x + 1);

        for (int y = 0; y < size - x - 1; y++)
        {          
            if (b[y] > b[y + 1])
            {               
                temp = b[y];
                b[y] = b[y + 1];
                b[y + 1] = temp;
                
                // Print elements being swapped
                printf("Swapping: %d and %d\n", b[y], b[y + 1]);
            }
            else
            {
                // Print elements not being swapped
                printf("Not swapping: %d and %d\n", b[y],b[y+ 1]);
            }
        }

        // Print array after each iteration
        printf("Array after iteration %d: ", x + 1);
        for (int z = 0; z < size; z++)
        {
            printf("%d ", b[z]);
        }
        printf("\n\n");
    }
    
    printf("\nFirst array after implementing bubble sort: ");
    for (int x = 0; x < size; x++)
    {
        printf("%d  ", a[x]);
    }
    
    printf("\nSecond array after implementing bubble sort: ");
    for (int x = 0; x < size; x++)
    {
        printf("%d  ", b[x]);
    }


    return 0;
}

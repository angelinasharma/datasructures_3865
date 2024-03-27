### Array
- Using dynamic array size declaration 
	- either globally define the size variable (would be static)
	- first declare the variable and take input from user and then declare the array
	- error otherwise:
```
error: ‘size’ undeclared (first use in this function); did you mean ‘size_t’?
    5 |     int A[size], size;
      |           ^~~~
      |           size_t
observations.c:5:11: note: each undeclared identifier is reported only once for each function it appears in
```

- Not using & in scanf 
```c
#include <stdio.h>

int main()

{

int size;

printf("Enter the size: ");
scanf("%d", size);

int A[size];

}
```

- warning produced
```
terminated by signal SIGSEGV (Address boundary error)
```

- unsure where and how to put do-while loop without using functions
- if you enter a letter instead of a number it goes into an infinite loop
---
### Linked list

- **New node** 
```c
Newnode =  (struct Node*)malloc(sizeof(struct Node))
```
- (struct Node*) - Type-casting for the memory allocation 
- malloc - memory allocation
- sizeof() - how much memory to allocate
- struct Node - the structure in which the memory needs to be allocated 

- rand() function - 

- variable declared inside a switch case cannot be used outside it, variable has to be declared outside switch case - scope error
- 
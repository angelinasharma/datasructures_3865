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

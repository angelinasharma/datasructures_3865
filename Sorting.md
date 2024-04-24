## Sorting 
- arranging elements in a particular order as per requirements of the user 
- no. of comparisons done to complete the job
	- Space Complexity
		- (variables and loops occupy the most space)
	- Time Complexity
		- Best(Low)
		- Average
		- Worst(High)

#### Insertion Sort

best case running time -> O(n)
worst case running time -> O(n^2)
###### Advantages
1. This algorithm is always beneficial in small set of data
2. This algorithm is efficient on substantially sorted 
3. It is 40% faster than selection sorter and twice as faster than bubble sort 
4. It requires less memory space (only O(1))
###### Algorithm
1. start from n to n-1
2. tmp = a[c];
3. q = c  - 1;
4. while(tmp < a[q])
	1. a[c] = a[q]    -> swapping condition
	2. q = q-1
	3. a[q + 1] = tmp 

---
#### Questions

- Diff b/w algorithm and program
- Diff b/w pseudocode and program
- Differentiate b/w function, module and procedure
- Define instructions 
- Differentiate b/w instruction and command
- Comparison b/w all sorting algos(after doing all in class)

---

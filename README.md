
# LABS-100
Labs from my CSE 100 Class for Spring 2022

- TABLE OF CONTENT
  1. LAB01
  2. LAB02
  3. LAB03
  4. LAB04_1
  5. LAB04_2


- IN PROGRESS
    - LAB05 (Skipping/Incomplete)
    - LAB06
    - LAB07
    - LAB08

## LAB01
This lab contains the code for implementing the Insertion-Sort Algorithm.  
I had to take a user's desired array size and create an insert their data manually.  
Once the elements were entered, we would then sort the array.  
After each iteration of insertSort(), I had to print the sub-array.  

### Example
#### Input
```
6
5
3
2
1
6
4
``` 
#### Output
```
3;5;
2;3;5;
1;2;3;5;
1;2;3;5;6
1;2;3;4;5;6;
```


## LAB02
This lab contains the code for the implementation of the Merge Sort Algorithm.  
Similar to Lab 01, I had to sort the array of the user's desired size except in this lab, I use merge sort.  
The program ends when the sorted array is printed.  

### Example
#### Input
```
6
5
3
2
1
6
4
``` 

#### Output
```
1;2;3;4;5;6;
```

## LAB03
To compile the code for LAB03 in the terminal you have to use the following:  

```
g++ jhernandez613_2.cpp -o a.out -std=c++11
```

In this lab I had to find a sequence in an array where the net change is maximized.  
In other words, a subarray of A whose values have the largest sum, **the maximum sub-array**.  
So, in this lab I am not applying a sorting algorithm.

### Example
#### Input
```
6
-3
11
-2
-3
10 
-5
```
#### Output
```
16
```

## LAB04_1
In this lab I had to implement the heap-sort algorithm. Where I would start with an integer number which 
indicated the number of elements (integers) that had to be sorted. Thereafter, the elements would be
entered one by one. At the end of the program, the elements were outputted in non-decreasing order with
each element having a semicolon following it.

### Example
#### Input
```
6
5
3
2
1
6
4
```

#### Output
```
1;2;3;4;5;6;
```

## LAB04_2
In this lab I had to implement the randomized quick-sort algorithm. In other words, a random pivot would be
chosen from the elements in an array when partitioning the sub-array. I would start with an integer which
indicates the number of elements (integers) that had to be sorted. The elements would be entered one-by-one.
At the end of the program, the elements were outputted in non-decreasing order with each element being
followed by a semicolon.

### Example
#### Input
```
6
5
3
2
1
6
4
```

#### Output
```
1;2;3;4;5;6;
```
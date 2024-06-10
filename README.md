
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

## LAB06

In LAB06 I had to implement a hash table that handles collisions by chaining. Using either linked list.  
I had to implement the insert, search, and delete operations. The keys would be integers with the assumption
that all keys would be non-negative. The first input would be the size `m` of the chained hash table.
I would have to use the simple hash function `h(k) = k mod m`.  
Then lines will follow starting with `i`, `s`, `d`, `o`, or `e`.

- `i` followed by a value such as `i2` will insert `2` into the table.
  - Nothing would be outputted in this case.

- `s` followed by a value such as `s2` will search for `2` in the table.
  - if there is an element with the key value, then `(key):FOUND_ATi,j;` will be outputted.
    - if there are various elements with the same key value the first instance will be outputted, not all of them.
  - otherwise, `(key):NOT_FOUND;` will be outputted.

- `d` followed by a value such as `d2` will delete `2` from the table.
  - If the delete was successful then `(key):DELETED;` will be outputted.
    - If there are various elements with the same key value, then the first instance will be deleted, not all of them.
  - Otherwise, `(key):DELETE_FAILED;` will be outputted.

- `o` will simply output the current state of the entire hash table.
  - An example would be (if `m = 3`and `3`, `6`, and `1` were inserted):
  ```
  0:6->3->;
  1:1->;
  2:;
  ```
  
- `e` simply terminates the program.

### Example

#### Input and Output

```
2
i4
i2
i6
i3
o
0:6->2->4->;
1:3->;
s2
2:FOUND_AT0,1;
s4
4:FOUND_AT0,2;
d5
5:DELETE_FAILED;
d2
2:DELETED;
o
0:6->4->;
1:3->;
e
```
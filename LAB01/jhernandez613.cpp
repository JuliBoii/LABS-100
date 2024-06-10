#include <iostream>

/*
 * Insertion Sort is based off the pseudocode from Introduction to Algorithms, 3rd Edition
 * by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein
 *
 * I only initialized my array at zero rather than one.
 */

//  This function will be printing the various stages of Insertion-Sort
void print(int A[], int n) {
    //  This for loop will be printing the elements in the sorted sub-array, after A[j] was sorted in.
    //  There will be a semicolon to separate each element in the sub-array
    for (int i = 0; i <= n; i++) {
        std::cout << A[i] << ";";
    }
    std::cout << std::endl;
}

//  This will be sorting the array with the Insertion-Sort Algorithm
void insertSort(int A[], int size) {
    int i, key; //The variables we will be using to store the sub-array size (i) and the element we want to sort (key)
    for (int j = 1; j < size; j++) {
        key = A[j]; // Store the element we want to sort
        i = j - 1;  // Initialize the size of the sub-array we will be going through

        //  The while loop will be traversing our sub-array A[0...j-1]
        //  Stops when we find an element that is not bigger than our key or when we reach the end of the sub-array
        //  If we reach the end of the sub-array, the key is the smallest element
        while (i > -1 && A[i] > key) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key; // Insert the key into the sub-array
        print(A, j);    // Print the current Insertion-Sort Iteration.
    }
}

int main() {
    int *A; // The user array that will store the elements
    int size;   //  Variable that will store the size of the array

    //  We take the users desired array size.
    std::cin >> size;

    //  Make an array of the users desired size
    A = new int[size];

    //  Insert the elements of the user into the array
    for (int i = 0; i < size; i++) {
        std::cin >> A[i];
    }

    //  Sort the user array with the Insertion-Sort Algorithm
    insertSort(A, size);

    delete[] A;

    return 0;
}
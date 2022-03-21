#include <iostream>

/*
 * Merge Sort and Merge is based off the pseudocode from Introduction to Algorithms, 3rd Edition
 * by Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein
 */

void print(int A[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << A[i] << ";";
    }
}

void merge(int A[], int low, int mid, int high) {
    int n1 = mid - low + 1; //  Size of left array
    int n2 = high - mid;    //  Size of right array

    int i, j, k;

    int L[n1], R[n2];   // Left and Right array being initialized

//    Filling the left array with the elements in the original array
    for (i = 0; i < n1; i++) {
        L[i] = A[low + i];
    }

//    Filling the right array with the elements in the original array
    for (j = 0; j < n2; j++) {
        R[j] = A[mid + j + 1];
    }

    // resets i and j to zero
    i = 0;
    j = 0;

    /*
     * Comparing the left and right array to see which array holds a smaller element
     * When the smallest element for the iteration is found, it is inserted into the original array
     * The for loop continues until both i and j match the counts of the left and right array respectively.
     */
    for (k = low; i < n1 && j < n2; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        }
        else {
            A[k] = R[j++];
        }
    }

    /*
    * If the left array (L[]) has more elements than the right
    * Then the remaining elements of L[] will go into arr[]
    */
    while (i < n1) {
        A[k++] = L[i++];
    }

    /*
     * If the right array (R[]) has more elements than the left
     * Then the remaining elements of R[] will go into arr[]
     */
    while (j < n2) {
        A[k++] = R[j++];
    }
}

//  This function will recursively divide the array
//  Then the various arrays will merge when merge() is called
void mergeSort(int A[], int low, int high) {
    if (low < high) {
        int q = (low + high) / 2;
        mergeSort(A, low, q);
        mergeSort(A, q + 1, high);
        merge(A, low, q, high);
    }
}


int main() {
    int *A;
    int size;

    std::cin >> size;

    A = new int[size];

    for (int i = 0; i < size; i++) {
        std::cin >> A[i];
    }
    // Calling the mergeSort function, passing the array, knowing the low is 0, index-wise, and passing the high as the users desired array size - 1
    mergeSort(A, 0, size - 1);

    //  Prints the final array after mergeSort() is accomplished
    print(A, size);

    return 0;
}
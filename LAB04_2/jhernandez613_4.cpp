#include <iostream>
#include <cstdlib>
#include <ctime>

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

/*
 * Places the pivot at its correct position in the array
 * Positions elements smaller or equal to the left of the pivot
 * Those greater than the pivot are positioned to the right of pivot
 */
int partition(int A[], int low, int high) {
    // Takes the last element in array as pivot
    int pivot = A[high];
    // Index of smaller element
    int i = low - 1;

    for(int j = low; j <= high - 1; j++) {
        // If the j position element is smaller than or equal to the pivot
        if (A[j] <= pivot) {
            i++; // increment index of the smaller element
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[high]);
    return (i + 1);
}

/*
 *  Generates a random pivot
 *  Then swaps the element at the random position with the end of the array
 *  Lastly calls the partition function
 */
int randPartition(int A[], int low, int high) {
    srand(time(NULL));

    int range = high - low;
    int i = low + rand() % range; // Generates a random number between the low and high

    // Swaps the element at the randomly generated position to the end
    swap(&A[i], &A[high]);

    return partition(A, low, high);
}

// Implementation of quickSort()
void quickSort(int A[], int low, int high) {
    if (low < high) {
        // q is the partitioning index
        int q = randPartition(A, low, high);
        quickSort(A, low, q - 1);
        quickSort(A, q + 1, high);
    }
}

void print(int A[], int n) {
    for(int i = 0; i < n; i++) {
        std::cout << A[i] << ";";
    }
}

int main() {
    int *A;
    int size;

    std::cin >> size;

    A = new int[size];

    for(int i = 0; i < size; i++) {
        std::cin >> A[i];
    }

    quickSort(A, 0, size - 1);

    print(A, size);

    delete[] A;

    return 0;
}
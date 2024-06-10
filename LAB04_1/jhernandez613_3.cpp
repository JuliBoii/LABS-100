#include <iostream>

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

// returns the position of left node of the parent
int leftNode(int i) {
    return (2 * i + 1);
}

// returns the position of right node of the parent
int rightNode(int i) {
    return (2 * i + 2);
}

/*
 * Heapify a subtree rooted with node i
 * With i being an index in the array
 */
void heapify(int A[], int size, int i) {
    int l = leftNode(i);
    int r = rightNode(i);
    int largest = i; // Initializes largest as root/parent position

    // If the left node is bigger than the parent
    // And the index of the left node is in the array
    // Then largest is set as the position of the left node
    if (A[l] > A[largest] && l < size) {
        largest = l;
    }

    // If the right node is bigger than the parent
    // And the index of the right node is in the array
    // Then largest is set as the position of the right node
    if (A[r] > A[largest] && r < size) {
        largest = r;
    }

    // Checks to see if the current largest position is not the same as the initial parent position
    if (largest != i) {
        swap(&A[i], &A[largest]);    // Swaps the element in the parent position with the element at the current largest position
        heapify(A, size, largest);      // recursively heapify the affected subtree
    }

}

void buildMaxHeap(int A[], int size) {
    // Index of the last non-leaf node
    int p = ((size/2) - 1);

    // from last non-leaf node and heapify each node
    for (int i = p; i >= 0; i--) {
        heapify(A, size, i);
    }
}

void heapSort(int A[], int size) {
    buildMaxHeap(A, size); // Builds Heap

    // Extracting elements from heap one by one
    for (int i = size - 1; i >= 0; i--) {
        swap(&A[0], &A[i]); // Exchanges the current node to the end
        heapify(A, i, 0); // Calls heapify  on the reduced heap
    }
}

void print(int A[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << A[i] << ";";
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

    heapSort(A, size);

    print(A, size);

    delete[] A;

    return 0;
}

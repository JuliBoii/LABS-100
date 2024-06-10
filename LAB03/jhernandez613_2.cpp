#include <iostream>
#include <tuple>

/*
 * Used the following resources to help me understand how a tuple works
 * While also helping me understand how to use tuple in c++
 * https://en.cppreference.com/w/cpp/utility/tuple
 * https://youtu.be/33Y_5gOyi3Y
 * https://youtu.be/YiVFO_e05N4
 * https://youtu.be/VFmyZg7zJ3s
 *
 * My code was constantly outputting error messages when I tried to compile my code in the terminal
 * This forum helped me resolve that issue
 * https://stackoverflow.com/a/65921027
 */

std::tuple<int, int, int> findMaxCrossSub(const int arr[], int low, int mid, int high) {
    // Lines 20 - 34, find a max subarray of the left half
    int leftSum = INT_MIN;  //  Initialize the left sum, which holds the greatest sum found so far
    int maxLeft;
    int sum = 0;    //  Holds the sum entries in arr[i..mid]

    // starts the index i at mid and works down to low, which is set as (low - 1) inorder for i = low
    for (int i = mid; i > low - 1; i--) {
        sum = sum + arr[i];
        if (sum > leftSum) {
            // When we find a subarray with a sum of greater than leftSum
            // Update leftSum to this subarray sum
            leftSum = sum;
            // Update the variable maxLeft to record this index i
            maxLeft = i;
        }
    }

    // Lines 37 - 51, find a max subarray of the right half
    int rightSum = INT_MIN; //  Initialize the right sum, which holds the greatest sum found so far
    int  maxRight;
    sum = 0;    //  Resets the sum from previous iterations, holds the sum entries in arr[j...high]

    // starts the index j at mid + 1, to not account mid that is in the left subarray, and works up to high, which is set as (high + 1) inorder for j = high
    for (int j = mid + 1; j < high + 1; j++) {
        sum = sum + arr[j];
        if (sum > rightSum) {
            // When we find a subarray with a sum of greater than rightSum
            // Update rightSum to this subarray sum
            rightSum = sum;
            // Update the variable maxRight to record this index j
            maxRight = j;
        }
    }

    //  returns the indices maxLeft and maxRight that demarcate a max subarray crossing the midpoint
    //  along with (leftSum + rightSum) of the values in the subarray arr[leftMax...rightMax]
    return std::make_tuple(maxLeft, maxRight, leftSum + rightSum);
}

// Initial call of findMaxSub will find a max subarray of arr[low...high]
std::tuple<int, int, int> findMaxSub(int A[], int low, int high) {
    std::tuple<int, int, int> leftArr;
    std::tuple<int, int, int> rightArr;
    std::tuple<int, int, int> crossArr;

    //tests for the base case, where the sub has just one element
    if (high == low){
        // returns a tuple with the starting and ending indices of jus the one element, along with its value
        return std::make_tuple(low, high, A[low]);
    }
    // line 59-85 handle the recursive case
    else {
        int mid = (low + high) / 2 ; // divides the array, finding the index mid

        // conquer by recursively finding max subarray within the left and right array
        leftArr = findMaxSub(A, low, mid);
        rightArr = findMaxSub(A, mid + 1, high);

        // line 68-84, form the combine part
        // Finds a maximum subarray that crosses the midpoint
        crossArr = findMaxCrossSub(A, low, mid, high);

        // Test whether the left sub array contains a subarray with the max sum
        // If it does, it returns max subarray
        if (std::get<2>(leftArr) >= std::get<2>(rightArr) && std::get<2>(leftArr) >= std::get<2>(crossArr)) {
            return leftArr;
        }
        // Otherwise, it tests whether the right subarray contains a subarray with the max sum
        // If it does, it returns max subarray
        else if (std::get<2>(rightArr) >= std::get<2>(leftArr) && std::get<2>(rightArr) >= std::get<2>(crossArr)) {
            return rightArr;
        }
        // If neither the left nor right contain the max
        // then the max subarray must cross the mid, so it is returned
        else {
            return crossArr;
        }
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

    //  Tuple output receives 3 numbers being <0>, <1>, and <2>
    //  representing the start of the max sub array, the end of the max sub array
    //  and the sum of the values in that max sub array
    std::tuple<int, int, int> output = findMaxSub(A, 0, size - 1);

    // Prints the sum of the max sub array, with 2 representing the position value of the sum in the tuple
    std::cout << std::get<2>(output);

    delete[] A;

    return 0;
}
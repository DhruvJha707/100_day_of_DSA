/*Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104*/

#include <stdio.h>

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition (Lomuto)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

// Quickselect
int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);

        if (pi == k)
            return arr[pi];
        else if (pi < k)
            return quickSelect(arr, pi + 1, high, k);
        else
            return quickSelect(arr, low, pi - 1, k);
    }
    return -1;
}

int findKthLargest(int nums[], int n, int k) {
    return quickSelect(nums, 0, n - 1, n - k);
}

int main() {
    int nums[] = {3,2,1,5,6,4};
    int n = sizeof(nums)/sizeof(nums[0]);
    int k = 2;

    printf("Kth largest: %d", findKthLargest(nums, n, k));
    return 0;
}
/*Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] <= 106
1 <= k <= min(50, nums.length)*/

#include <stdio.h>

// Check if we can split into <= k subarrays with max sum <= mid
int canSplit(int nums[], int n, int k, int mid) {
    int count = 1;
    int curr_sum = 0;

    for (int i = 0; i < n; i++) {
        if (curr_sum + nums[i] <= mid) {
            curr_sum += nums[i];
        } else {
            count++;
            curr_sum = nums[i];

            if (count > k) {
                return 0; // Not possible
            }
        }
    }
    return 1; // Possible
}

int splitArray(int nums[], int n, int k) {
    int low = nums[0];
    int high = 0;

    // Find max element and total sum
    for (int i = 0; i < n; i++) {
        if (nums[i] > low)
            low = nums[i];
        high += nums[i];
    }

    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canSplit(nums, n, k, mid)) {
            result = mid;
            high = mid - 1; // try smaller
        } else {
            low = mid + 1; // increase
        }
    }

    return result;
}

int main() {
    int nums[] = {7, 2, 5, 10, 8};
    int n = 5;
    int k = 2;

    printf("%d\n", splitArray(nums, n, k)); // Output: 18

    return 0;
}
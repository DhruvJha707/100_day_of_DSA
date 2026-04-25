/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums contains distinct values sorted in ascending order.
-104 <= target <= 104*/


#include <stdio.h>

int searchInsert(int nums[], int n, int target) {
    int low = 0, high = n - 1;
    int ans = n;  // default insertion at end

    while (low <= high) {
        int mid = (low + high) / 2;

        if (nums[mid] >= target) {
            ans = mid;
            high = mid - 1;  // search left
        } else {
            low = mid + 1;   // search right
        }
    }

    return ans;
}

int main() {
    int n, target;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &target);

    int result = searchInsert(nums, n, target);
    printf("%d\n", result);

    return 0;
}
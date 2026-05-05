/*Easy
Topics
premium lock icon
Companies
Hint
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
Example 2:

Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
 

Constraints:

1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.*/

#include <stdio.h>

#define MAX 1001

void relativeSort(int arr1[], int n, int arr2[], int m) {
    int count[MAX] = {0};

    // Step 1: Count frequency of arr1
    for (int i = 0; i < n; i++) {
        count[arr1[i]]++;
    }

    int index = 0;

    // Step 2: Place elements as per arr2 order
    for (int i = 0; i < m; i++) {
        while (count[arr2[i]] > 0) {
            arr1[index++] = arr2[i];
            count[arr2[i]]--;
        }
    }

    // Step 3: Place remaining elements in ascending order
    for (int i = 0; i < MAX; i++) {
        while (count[i] > 0) {
            arr1[index++] = i;
            count[i]--;
        }
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main() {
    int arr1[] = {2,3,1,3,2,4,6,7,9,2,19};
    int arr2[] = {2,1,4,3,9,6};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    printf("Original arr1:\n");
    printArray(arr1, n);

    relativeSort(arr1, n, arr2, m);

    printf("Sorted arr1:\n");
    printArray(arr1, n);

    return 0;
}
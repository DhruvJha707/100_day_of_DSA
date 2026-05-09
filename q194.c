/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
Example 3:

Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104*/

#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting
int compare(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

// Function to merge intervals
int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {

    // Step 1: Sort intervals
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    // Allocate result
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int idx = 0;

    // Copy first interval
    result[idx] = (int*)malloc(2 * sizeof(int));
    result[idx][0] = intervals[0][0];
    result[idx][1] = intervals[0][1];
    (*returnColumnSizes)[idx] = 2;
    idx++;

    // Step 2: Merge intervals
    for (int i = 1; i < intervalsSize; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // Last interval in result
        int* last = result[idx - 1];

        if (start <= last[1]) {
            // Merge
            if (end > last[1])
                last[1] = end;
        } else {
            // Add new interval
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = start;
            result[idx][1] = end;
            (*returnColumnSizes)[idx] = 2;
            idx++;
        }
    }

    *returnSize = idx;
    return result;
}

// Driver code for testing
int main() {
    int intervalsSize = 4;
    int intervalsColSize[] = {2,2,2,2};

    int** intervals = (int**)malloc(intervalsSize * sizeof(int*));
    intervals[0] = (int[]){1,3};
    intervals[1] = (int[]){2,6};
    intervals[2] = (int[]){8,10};
    intervals[3] = (int[]){15,18};

    int returnSize;
    int* returnColumnSizes;

    int** ans = merge(intervals, intervalsSize, intervalsColSize,
                      &returnSize, &returnColumnSizes);

    printf("Merged intervals:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d,%d] ", ans[i][0], ans[i][1]);
    }

    return 0;
}
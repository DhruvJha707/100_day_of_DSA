/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/

#include <stdio.h>
#include <stdlib.h>

// Interval structure
struct Interval {
    int start;
    int end;
};

// Compare function for sorting by start time
int compare(const void *a, const void *b) {
    struct Interval *i1 = (struct Interval *)a;
    struct Interval *i2 = (struct Interval *)b;
    return i1->start - i2->start;
}

// Function to merge intervals
void mergeIntervals(struct Interval arr[], int n) {
    if (n == 0) return;

    // Step 1: Sort intervals
    qsort(arr, n, sizeof(struct Interval), compare);

    // Temporary array to store result
    struct Interval res[n];
    int index = 0;

    // Step 2: Initialize with first interval
    res[index++] = arr[0];

    // Step 3: Traverse remaining intervals
    for (int i = 1; i < n; i++) {
        // Get last added interval
        struct Interval last = res[index - 1];

        // If overlapping → merge
        if (arr[i].start <= last.end) {
            res[index - 1].end = (last.end > arr[i].end) ? last.end : arr[i].end;
        }
        else {
            // No overlap → add new interval
            res[index++] = arr[i];
        }
    }

    // Print result
    printf("Merged intervals:\n");
    for (int i = 0; i < index; i++) {
        printf("[%d, %d] ", res[i].start, res[i].end);
    }
    printf("\n");
}

// Driver code
int main() {
    struct Interval arr[] = {{1,3}, {2,6}, {8,10}, {15,18}};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergeIntervals(arr, n);
    return 0;
}
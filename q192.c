/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/

#include <stdio.h>
#include <stdlib.h>

// Structure for meeting interval
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

// Min Heap functions
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int heap[], int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}

// Insert into heap
void push(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

// Remove min
void pop(int heap[], int *size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapifyDown(heap, *size, 0);
}

// Get min
int top(int heap[]) {
    return heap[0];
}

// Function to find minimum rooms
int minMeetingRooms(struct Interval arr[], int n) {
    // Step 1: Sort by start time
    qsort(arr, n, sizeof(struct Interval), compare);

    int heap[n];
    int size = 0;

    // Step 2: Add first meeting
    push(heap, &size, arr[0].end);

    // Step 3: Process remaining meetings
    for (int i = 1; i < n; i++) {
        if (arr[i].start >= top(heap)) {
            pop(heap, &size); // reuse room
        }
        push(heap, &size, arr[i].end);
    }

    return size;
}

// Driver code
int main() {
    struct Interval arr[] = {{0,30}, {5,10}, {15,20}};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Minimum rooms required: %d\n", minMeetingRooms(arr, n));
    return 0;
}
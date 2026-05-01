/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.*/

#include <stdio.h>

int canPaint(int boards[], int n, int k, int max_time) {
    int painters = 1;
    int curr_time = 0;

    for (int i = 0; i < n; i++) {
        if (curr_time + boards[i] <= max_time) {
            curr_time += boards[i];
        } else {
            painters++;
            curr_time = boards[i];

            if (painters > k) {
                return 0; // Not possible
            }
        }
    }
    return 1; // Possible
}

int minTime(int boards[], int n, int k) {
    int low = boards[0];
    int high = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > low)
            low = boards[i];
        high += boards[i];
    }

    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(boards, n, k, mid)) {
            result = mid;
            high = mid - 1; // Try smaller value
        } else {
            low = mid + 1; // Increase time
        }
    }

    return result;
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%d\n", minTime(boards, n, k));

    return 0;
}
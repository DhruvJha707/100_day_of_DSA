/*Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

Input:
- First line: an integer n

Output:
- Print the integer square root of n

Examples:
Input:
64

Output:
8

Input:
20

Output:
4

Input:
1

Output:
1

Explanation:
Binary Search is applied on the range 0 to n. At each step, the middle value is squared and compared with n. If mid * mid equals n, mid is the square root. If mid * mid is less than n, search continues in the right half; otherwise, in the left half. The final answer is the largest integer whose square does not exceed n.*/


#include <stdio.h>

int integerSqrt(int n) {
    int low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long square = (long long)mid * mid;

        if (square == n) {
            return mid;
        }
        else if (square < n) {
            ans = mid;      // store possible answer
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d", integerSqrt(n));

    return 0;
}
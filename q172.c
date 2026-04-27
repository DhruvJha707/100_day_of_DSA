/*Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 

Constraints:

0 <= x <= 231 - 1*/

#include <stdio.h>

int mySqrt(int x) {
    if (x == 0 || x == 1) return x;

    int low = 1, high = x / 2;
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Avoid overflow: use division instead of mid*mid
        if (mid <= x / mid) {
            ans = mid;          // valid answer
            low = mid + 1;      // try bigger
        } else {
            high = mid - 1;     // go smaller
        }
    }

    return ans;
}

int main() {
    int x;
    scanf("%d", &x);

    printf("%d", mySqrt(x));
    return 0;
}
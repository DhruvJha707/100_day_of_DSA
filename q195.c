/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.*/

#include <stdio.h>
#include <stdlib.h>

// Structure to store car data
struct Car {
    int position;
    double time;
};

// Comparator for sorting in descending order of position
int compare(const void *a, const void *b) {
    struct Car *c1 = (struct Car *)a;
    struct Car *c2 = (struct Car *)b;
    
    if (c2->position > c1->position) return 1;
    else return -1;
}

int carFleet(int target, int position[], int speed[], int n) {
    struct Car cars[n];

    // Step 1: Calculate time for each car
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }

    // Step 2: Sort cars by position descending
    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    double maxTime = 0;

    // Step 3: Count fleets
    for (int i = 0; i < n; i++) {
        if (cars[i].time > maxTime) {
            fleets++;
            maxTime = cars[i].time;
        }
    }

    return fleets;
}

// Driver code
int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = 5;

    int result = carFleet(target, position, speed, n);
    printf("Number of Car Fleets: %d\n", result);

    return 0;
}
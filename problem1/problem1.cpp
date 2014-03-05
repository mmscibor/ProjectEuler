#include <iostream>
using namespace std;

#define MAX_VALUE 1000 // Number of multiples of 3 || 5 under 1000 can't exceed 1000

int multOfThree[MAX_VALUE], multOfFive[MAX_VALUE]; // Initializes to 0, useful

int main() {
    // Fine all multiples of 3 and 5
    for (int i = 3, j = 0; i < 1000; i += 3, j++) {
        multOfThree[j] = i;
    }

    for (int i = 5, j = 0; i < 1000; i += 5, j++) {
        multOfFive[j] = i;
    }

    // Set intersection to 0
    for (int i = 0; i < MAX_VALUE; i++) {
        if (multOfThree[i] % 5 == 0) {
            multOfThree[i] = 0;
        }
    }

    int sum = 0;

    for (int i = 0; i < MAX_VALUE; i++) {
        sum += multOfThree[i];
        sum += multOfFive[i];
    }

    cout << sum << endl;

    return 0;
}

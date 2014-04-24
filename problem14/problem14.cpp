#include <iostream>
using namespace std;

#define LIMIT 1000000

long collatzIterator(long value) {
    if (value % 2 == 0) {
        return (value / 2);
    } else {
        return ((3 * value) + 1);
    }
}

int main() {
    int maxLength = 1;
    int maxValue = 1;

    long * collatzValue = new long[LIMIT];

    for (long initialValue = 1; initialValue < LIMIT; initialValue++) {
        long value = initialValue;
        int length = 1;
        while (value != 1) {
            value = collatzIterator(value);
            if (value < initialValue) {
                length += collatzValue[value - 1];
                break;
            }
            length++;
        }
        collatzValue[initialValue - 1] = length;
    }

    for (int iterator = 1; iterator < LIMIT; iterator++) {
        if (collatzValue[iterator] > maxLength) {
            maxValue = iterator;
            maxLength = collatzValue[iterator - 1];
        }
    }

    cout << "Longest chain at value: " << maxValue << endl;
    cout << "Chain length: " << maxLength << endl;
}

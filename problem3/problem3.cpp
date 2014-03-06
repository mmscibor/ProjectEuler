#include <iostream> 
#include <math.h>
using namespace std;

#define VALUE 600851475143

int largestPrime = 0;
int highestFactor;

bool isPrime(int factor) {
    for (int i = 2; i < factor; i++) {
        if (factor % i == 0 && i != factor) {
            return false;
        }
    }
    return true;
}

// Finds the largest factor of a number up to its square root,
// then recursively implements itself on value / factor until
// factor is prime.

void factor(long value) {
    highestFactor = 0;

    int rootValue = (int) sqrt(value);
    for (int i = 1; i < rootValue; i++) {
        if (value % i == 0) {
            highestFactor = i;
        }
    }

    if (isPrime(highestFactor) && highestFactor > largestPrime) {
        largestPrime = highestFactor;
    }

    int otherFactor = value / highestFactor; 

    if (isPrime(otherFactor) && otherFactor > largestPrime) {
        largestPrime = otherFactor;
    }

    if (!isPrime(highestFactor)) {
        factor(highestFactor);
        factor(otherFactor);
    }
}

int main() {
    factor(VALUE);
    cout << largestPrime << endl;
}

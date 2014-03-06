#include <iostream>
#include <math.h>
using namespace std;

#define MAX_TERM 4000000

int numbers[MAX_TERM];

// Mathematical shortcut to determine if number is Fibonacci
int isFibonacci(int n) {
    long upperTest = 5 * pow(n, 2) + 4;
    long lowerTest = 5 * pow(n, 2) - 4;

    double upperTestRoot = sqrt(upperTest), lowerTestRoot = sqrt(lowerTest);

    int upper = (int) upperTestRoot, lower = (int) lowerTestRoot;

    if (upper == upperTestRoot || lower == lowerTestRoot) {
        return n;
    } else {
        return 0;
    }
}

int main() {
    for (int i = 0; i < MAX_TERM; i++) {
        numbers[i] = isFibonacci(i);
        // If Fibonacci set number, else = 0
    }

    int sum = 0;

    for (int i = 0; i < MAX_TERM; i++) {
        if (numbers[i] != 0 && numbers[i] % 2 == 0) {
            sum += numbers[i];
            cout << sum << endl;
        }
    }

    cout << sum << endl;
}

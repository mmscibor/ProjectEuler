#include <iostream>
using namespace std;

int main() {
    int number = 1;
    for (int i = 1; i <= 10; i++) {
        if (number % i != 0) {
            number *= i;
        }
        cout << "Number at " << i << " is " << number << endl;
    }

    for (int i = 2; i <= 10; i++) {
        bool isProduct = false;
        for (int j = 2; j <= i; j++) {
            for (int k = 2; k <= i; k++) {
                if (j*k == i) {
                    isProduct = true;
                }
            }
        }
        
        if (isProduct) {
            
        }
    }


    cout << "Number is: " << number << endl;
}

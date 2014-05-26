#include <iostream>
using namespace std;

int main() {
    int digits[1000];
    fill_n(digits, 1000, -1);
    digits[0] = 2;

    for (int i = 1; i < 1000; i++) { // Middle argument is power, here 2 ^ 1000
        for (int j = 0; ; j++) { // Go through array, double every element
            if (digits[j] == -1) {
                break;
            }
            digits[j] *= 2;
        }

        for (int j = 0; ; j++) { // Go through array, make sure only one digit per container
            if (digits[j] == -1) {
                break;
            }
            int temp = digits[j];
            if (temp / 10 != 0) {
                digits[j] = temp % 10;
                if (digits[j + 1] == -1) {
                    digits[j + 1] = temp / 10;
                } else {
                    digits[j + 1] += temp / 10;
                }
            }
        }
    }

    int sumDigits = 0;

    for (int i = 999; i >= 0; i--) { // Sum digits
        if (digits[i] != -1) {
            sumDigits += digits[i];
        }
    }

    cout << sumDigits << endl;
}

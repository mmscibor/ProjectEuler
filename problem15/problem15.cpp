#include <iostream>
using namespace std;

#define HEIGHT 21
#define WIDTH 21

long matrix[HEIGHT][WIDTH];

void setValue(int row, int column) {
    long value = 0;
    int initRow = row;
    int scalar = 1;
    do {
        value += matrix[row][column + 1];
        row++;
        scalar++;
    } while (row < HEIGHT);

    matrix[initRow][column] = value;
}

int main() {
    for (int i = 0; i < HEIGHT; i++) {
        matrix[i][WIDTH - 1] = 1;
    }

    for (int row = HEIGHT - 1; row >= 0; row--) {
        for (int col = WIDTH - 2; col >= 0; col--) {
            setValue(row, col);
        }
    }

    cout << "Top left corner: " << matrix[0][0] << endl;
}

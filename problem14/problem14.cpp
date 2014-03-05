#include <iostream>
using namespace std;

#define ELEMENTS 1000000
#define SUBSET 100000
#define STARTPOINT 800000

int determinedLengths [ELEMENTS];
int length = 1, determinedNum = 0;

int collatzChain(int collatzNum){
    if (collatzNum == 1){
        return length;
    }

    if (collatzNum <= determinedNum) {
        return length + determinedLengths[collatzNum-1] - 1;
    }

    length++;

    if (collatzNum % 2 == 0){
        collatzNum = collatzNum / 2;
        collatzChain(collatzNum);
    } else {
        collatzNum = collatzNum * 3 + 1;
        collatzChain(collatzNum);
    }
}

int main(){ 
    for (int i=0; i < SUBSET; i++) {
        determinedLengths[i] = collatzChain(i+1);
        determinedNum = i+1;
        length = 1;
    }
/*    
    for (int i=STARTPOINT; i < ELEMENTS; i++) { 
        determinedLengths[i] = collatzChain(i+1);
        length = 1;
    }
*/
    for (int i=0; i < ELEMENTS; i++) {
        cout << determinedLengths[i] << endl;
    }
}

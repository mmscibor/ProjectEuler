#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    string line;
    ifstream summands ("summands.txt");
    int sumMatrix [100][50];
    int i, j = 0;

    if(summands.is_open()) {
        while(getline(summands, line)){
            for(i=0; i<line.length(); i++){
                sumMatrix[j][i] = line[i] - '0';
            }
            j++;
        }
        summands.close();
    }
   
    int stashSums [50];
    int placeHolder = 0, sum = 0;

    for (j=49; j>=0; j--){
        for (i=0; i<100; i++){
            sum += sumMatrix[i][j];
        }
        sum += placeHolder;
        if (sum > 9) {
            placeHolder = sum / 10;
        } else {
            placeHolder = 0;
        }
        stashSums[j] = sum % 10;
        sum = 0;
    }

    cout<<placeHolder;
    for(i=0;i<50;i++){
        cout<<stashSums[i];
    }
    cout<<endl;
    return 0;
}

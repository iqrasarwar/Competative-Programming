#include <iostream>
using namespace std;

void decimalToBinary(int n) {
    int binaryNum[32];
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n & 1;
        n = n >> 1;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << binaryNum[j];
    }
}

int main() {
    int n = 10;
    cout << "Binary representation of " << n << " is: ";
    decimalToBinary(n);
    return 0;
}

#include <iostream>
using namespace std;

int binaryToDecimal(int n) {
    int decimalNum = 0;
    int base = 1;
    while (n > 0) {
        int lastBit = n & 1;
        decimalNum += lastBit * base;
        n = n >> 1;
        base = base << 1;
    }
    return decimalNum;
}

int main() {
    int n = 1010;
    cout << "Decimal representation of " << n << " is: " << binaryToDecimal(n) << endl;
    return 0;
}

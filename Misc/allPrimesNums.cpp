#include <iostream>
using namespace std;

const int MAXN = 100;

bool isPrime[MAXN + 1];

void sieve() {
    // Initialize all numbers as prime
    for (int i = 2; i <= MAXN; i++) {
        isPrime[i] = true;
    }
    // Mark non-prime numbers
    for (int i = 2; i * i <= MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    sieve();
    for (int i = 2; i <= MAXN; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    return 0;
}

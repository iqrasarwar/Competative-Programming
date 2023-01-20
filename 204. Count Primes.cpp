class Solution {
public:
    int countPrimes(int n) {
        bool isPrime[n + 1];
        for (int i = 2; i <= n; i++) {
            isPrime[i] = true;
        }
        // int count = n-1;
        // Mark non-prime numbers
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                    // count--;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }
        return count;
    }
};

#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // input the number of test cases

    while (t--) { // iterate through each test case
        int n, k;
        cin >> n >> k; // input the array size and number of rotations

        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i]; // input the array elements
        }

        k = k % n; // handle the case when k > n

        for (int i = n - k; i < n; i++) {
            cout << a[i] << " "; // print the last k elements of the array
        }

        for (int i = 0; i < n - k; i++) {
            cout << a[i] << " "; // print the remaining elements of the array
        }

        cout << endl; // print a new line after each test case
    }

    return 0;
}

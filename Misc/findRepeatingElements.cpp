#include <iostream>
using namespace std;

void findRepeatingElements(int arr[], int n) {
    cout << "Repeating elements are: ";
    for (int i = 0; i < n; i++) {
        if (arr[abs(arr[i])] >= 0) {
            arr[abs(arr[i])] = -arr[abs(arr[i])];
        } else {
            cout << abs(arr[i]) << " ";
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 1, 3, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    findRepeatingElements(arr, n);
    return 0;
}

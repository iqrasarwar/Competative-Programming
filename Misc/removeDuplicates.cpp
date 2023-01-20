#include <iostream>
#include <unordered_set>
using namespace std;

void removeDuplicates(int arr[], int n) {
    unordered_set<int> set;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (set.find(arr[i]) == set.end()) {
            set.insert(arr[i]);
            arr[j++] = arr[i];
        }
    }
    for (int i = j; i < n; i++) {
        arr[i] = -1;
    }
}

int main() {
    int arr[] = {0,1,2,1,3,2,3,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    removeDuplicates(arr, n);
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] <<

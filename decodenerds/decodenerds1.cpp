// decodenerds_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int* vec = new int[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (vec[i] == 1)
            continue;
        for (int j = i; j < n; j++)
        {
            vec[i] = (vec[i] + 1) % 1;
            count++;
        }
    }
    cout << count;
    return 0;
}

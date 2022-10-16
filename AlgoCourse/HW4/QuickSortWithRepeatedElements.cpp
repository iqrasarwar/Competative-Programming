#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[100];

int partition(int i, int j, int pivot)
{
    int pival = arr[pivot];
    arr[pivot] = arr[i];
    arr[i] = pival;
    int ind = i+1;
    for (int k = i+1; k <= j; k++)
    {
        if (arr[k] == pival)
        {
            int temp = arr[ind];
            arr[ind] = pival;
            arr[k] = temp;
            ind++;
        }
    }
    cout << "All pivots at start:: ";
    for (int k = i; k <= j; k++)
    {
        cout << arr[k] << "\t";
    }
    //swap first and pivot values
    int p = ind, q = j,temp =0;
    while (q >= p)
    {
        //inc i while arr of i is less than arr of pivot
        if (arr[p] < arr[i])
            p++;
        else if (arr[q] > arr[i])
            q--;
        else
        {
            //swap arr of p & q
            temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
            p++;
            q--;
        }
    }
    int d = i;
    for (int k = 0; k < ind; k++)
    {
        int temp = arr[q];
        arr[q] = pival;
        arr[d] = temp;
        d++;
        q--;
    }
    cout << "\nPartitioned:: ";
    for (int z = i; z <= j; z++)
    {
        cout << arr[z] << "\t";
    }
    return q;
}
int main()
{
    arr[0] = 5;
    arr[1] = 8;
    arr[2] = 3;
    arr[3] = 7;
    arr[4] = 7;
    arr[5] = 2;
    arr[6] = 9;
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] <<"\t";
    }
    cout << endl;
    partition(0, 6,3);
    return 0;
}

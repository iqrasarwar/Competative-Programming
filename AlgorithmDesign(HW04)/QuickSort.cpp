#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[] = { 5,3,7,9,2,6,1 };
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
int partition( int i, int j, int pivot)
{
    //swap first and pivot values
    int temp = arr[pivot];
    arr[pivot] = arr[i];
    arr[i] = temp;
    int p = i + 1, q = j;
    while (q >= p)
    {
        //inc i while arr of i is less than arr of pivot
       if(arr[p] < arr[i])
            p++;
        else if(arr[q] > arr[i])
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
    temp = arr[i];
    arr[i] = arr[q];
    arr[q] = temp;
    
    return q;
}
int QuickSort( int i, int j)
{
	if (i < 0 || j < i || i == j || j < 0)
		return 0;
	int index = partition( i, j, i);
	QuickSort( i, index - 1);
	QuickSort(index + 1, j);
}
int main()
{
    for (int i = 0; i < 7; i++)
    {
        arr[i] = rand();
    }
    QuickSort( 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << endl;
    }
	return 0;
}

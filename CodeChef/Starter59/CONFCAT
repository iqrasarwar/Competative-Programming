#include <iostream>
#include<string>
using namespace std;

int main() {
	int t =0;
	cin >> t;
	while (t--)
	{
		int size;
		cin >> size;
		int* arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
		int a = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] > arr[a])
			{
				a = i;
				break;
			}
		}
		if (a == 0)
		{
			cout << "-1" << endl;
		}
		else
		{
			cout << a << endl;
			for (int i = 0; i < a; i++)
			{
				cout << arr[i] << " ";
			}
			cout <<endl<< size - a << endl;
			for (int i = a; i < size; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}

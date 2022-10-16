#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int p[1000], arr[1000];

void stops(int n, int arr[])
{
	p[0] = 0;
	for (int i = 1; i < n; i++)
	{
		p[i] = pow((200 - arr[i]), 2);														//penality for this i hotel
		cout << "Penality for " << arr[i] << " at index " << i << " is " << p[i] << endl;
		for (int j = 0; j < i; j++) 
		{
			int x = p[j] + pow((200 - (arr[j] - arr[i])), 2);								//penality if we stop at this j hotel to reach n 
			if (x < p[i])																   //if this penality is less than any perivious penality update it
				p[i] = x;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Penality for " << arr[i] << " at index " << i << " is " << p[i] << endl;
	}
	if (n > 0)
		cout << "Minimal Penalty :" << p[n - 1] << endl;
}

int main()
{
	int n;
	cout << "Enter Number Of Hotels::";
	cin >> n;
	cout << "Enter Hotels distance::";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	stops(n,arr);
	return 0;
}

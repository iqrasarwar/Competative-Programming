#include<iostream>
#include<algorithm>
using namespace std;

int MaxSumSeq(int arr[], int n)
{
	int currentMaxium = 0;
	int OverallMax = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = currentMaxium + arr[i];
		currentMaxium = max(arr[i], sum);
		OverallMax = max(currentMaxium, OverallMax);
	}
	return OverallMax;
}
int main()
{
	int n;
	cin >> n;
	int arr[1000];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout<<MaxSumSeq(arr,n);
}

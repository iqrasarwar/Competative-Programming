#include<iostream>
#include<algorithm>
using namespace std;

const int n = 1000;
const int m = 1000;
int arr[n][m];

void LCS(int arr[n][m], int x , int y)
{
	for (int i = 1; i < x; i++)
	{
		for (int j = 1; j < y; j++)
		{
			if (arr[i][0] != arr[0][j])
				arr[i][j] = 0;
			else
				arr[i][j] = arr[i - 1][j - 1] + 1;
		}
	}
}
int main()
{
	int x, y;
	string a, b;
	cin >> a >> b;
	x = a.length();
	y = b.length();
	for (int i = 1; i < x+1; i++)
	{
		arr[i][0] = a[i-1];
		arr[i][1] = 0;
	}
	for (int i = 1; i < y+1; i++)
	{
		arr[0][i] = b[i-1];
		arr[1][i] = 0;
	}
	LCS(arr,x+1,y+1);
	for (int i = 0; i < x+1; i++)
	{
		for (int j = 0; j < y+1; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

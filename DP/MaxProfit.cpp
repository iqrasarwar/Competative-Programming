#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int m[1000], Expectedprofit[1000],p[1000];
int k = 0;
int canOpenres(int a,int b)
{
	return a - b < k ? 0 : 1;
}
void stops(int n, int arr[])
{
	p[0] = 0;
	for (int i = 1; i < n; i++)
	{
		p[i] = 0;
		int t = 0;
		for (int j = 0; j < i; j++)
		{
			t = p[j] + arr[i] * canOpenres(m[i],m[j]);
			if (p[i] < t)
				p[i] = t;
		}
		if (p[i] < arr[i])
			p[i] = arr[i];
	}
}

int main()
{
	cout << "Enter k:: ";
	int n, x;
	cin >> k;
	cout << "Enter n::";
	cin >> n;
	cout << "Enter expected profit and distance from start";
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		Expectedprofit[i] = x;
		cin >> x;
		m[i] = x;
	}
	stops(n, Expectedprofit);
	for (int i = 0; i < n; i++)
	{
		cout << p[i] << endl;
	}
}

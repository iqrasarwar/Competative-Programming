#include<iostream>
#include<vector>
using namespace std;



int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> list[200];
	for (int i = 0; i < n;i++)
	{
		int a, b = 0;
		cin >> a >> b;
		list[a].push_back(b);
	}
	for (int i = 0; i < n; i++)
	{
		cout << i << " :";
		for (int j = 0; j < list[i].size(); j++)
		{
			cout << list[i][j] << " ";
		}
		cout << endl;
	}
	vector<int> newList[200];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < list[i].size(); j++)
		{
			newList[list[i][j]].push_back(i);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << i << " :";
		for (int j = 0; j < newList[i].size(); j++)
		{
			cout << newList[i][j] << " ";
		}
		cout << endl;
	}
}

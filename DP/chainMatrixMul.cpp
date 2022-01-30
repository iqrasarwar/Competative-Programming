#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll unsigned long long int

vector<pair<int, int>> vv;

int costOfMul(int i, int j)
{
	if (i == j) return 0; 
	int x = 0, k = 0,min=INT_MAX;
	for (k = i; k < j; k++)
	{
		x = costOfMul(i, k) + costOfMul(k + 1, j) + (vv[j].second * vv[i].first * vv[j].second);
		cout << x << endl;
		if (x < min)
			min = x;
	}
	return min;
}

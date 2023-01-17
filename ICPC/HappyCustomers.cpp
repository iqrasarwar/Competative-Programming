#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n, d;
	cin >> n >> d;
	int a, b;
	cin >> a >> b;
	vector<pair<int,int>> v;
	for (int i = 0; i < n; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		int temp = (t1 * a) + (t2 * b);
		v.push_back({ temp, i+1 });
	}
	sort(v.begin(), v.end());
	int i = 0, sum = 0;
	while (sum + v[i].first < d)
	{
		sum += v[i].first;
		i++;
	}
	cout << i << endl;
	for ( ;i>0;i--)
	{
		cout << v[i-1].second << " ";
	}
	return 0;
}

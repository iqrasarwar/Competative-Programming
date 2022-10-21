#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}
int main()
{
	int t;
	cin >> t;
	vector<int> v;
	vector<int> d;
	while (t)
	{
		int q;
		cin >> q;
		int num = 0;
		int per = 1;
		while (num < q)
		{
			v.push_back(per);
			per += per;
		}
		t--;
		int sum = 0;
		int daycount = 0;
		for (int i = v.size() - 1; i >= 0; i--)
		{
			if (sum + v[i] <= q)
			{
				sum += q;
				daycount++;
			}
		}
		d.push_back(daycount);
		v.clear();
	}
	print(d);
	return 0;
}

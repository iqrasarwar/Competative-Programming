Problem: PLPROCESS 

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
#define ll long long int
using namespace std;
const ll N = 100000;
int main() {
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, sum = 0;
		cin >> n;
		ll v[N];
		ll a[N];
		ll b[N];
		for (ll i = 0; i < n; i++)
		{
			cin >> v[i];
			sum += v[i];
		}
		partial_sum(v, v + n, a);
		for (ll i = 0; i < n; i++)
			b[i] = sum - a[i];
		ll min = INT32_MAX, res = v[0];
		for (ll i = 0; i < n; i++) {
			ll x = abs(a[i] - b[i]);
			if (x < min)
			{
				min = x;
				res = max(a[i], b[i]);
			}
		}
		cout << res << endl;
	}
	return 0;
}
Problem: NIBBLE 

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int x = n/4;
	    if(x*4 == n)
	    cout<<"GOOD"<<endl;
	    else
	    cout<<"NOT GOOD"<<endl;
	}
	return 0;
}

Problem: MOVIE2X

#include <iostream>
using namespace std;

int main() {
	int a,b;
	cin>>a>>b;
	int c = a-b;
	cout<<c+(b/2)<<endl;
	return 0;
}

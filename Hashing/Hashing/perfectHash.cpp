#include<iostream>
#include <List>
#include <ctime>
#include "perfectHashTable.h"
using namespace std;
ll prime = pow(2, 61) - 1;
ll p = prime - 1;
ll a = rand() % p + 1;
ll b = rand() % prime;
ll m = 100;


ll hashThisK(ll k, ll m,ll a,ll b,ll prime)
{
	ll hk = (((a * k) + b) % prime) % m;
	return hk;
}

int main()
{
	srand((unsigned)time(NULL));
	int n = 500;
	m = n;
	perfectHashTable* table = new perfectHashTable[n];
	int xx = 0;
	for (ll j = 0; j < n; j++)
	{
		ll x = pow(2, 64) - 1;
		ll value = rand() % x;
		ll index = hashThisK(value,n,a,b,prime);
		table[index].insert(index, value);
	}
	int x = 0;
	for (ll j = 0; j < n; j++)
	{
		cout << j << "::" << endl;
		x += table[j].printarr();
		cout << endl;
	}
	cout << x;
	return 0;
}
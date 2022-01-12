#include<iostream>
#include <cmath>
#include <vector>
#include "HashTable.cpp"
#define ll unsigned long long int
using namespace std;

ll prime = pow(2, 61) - 1;
ll p = prime - 1;
ll a = rand() % p + 1;
ll b = rand() % prime;
ll m = 5000;

int hash_a(int n)
{
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		ll x = pow(2, 64) - 1;
		ll k = rand() % x + 1;
		arr[i] = k;
	}
	for (int i = 0; i < n; i++)
	{
		int op = (rand() % 3)+1;
		if (op == 1)
		{
			//insert
			int hk = (((a * arr[i]) + b) % prime) % m;

		}
		else if (op == 2)
		{
			//delete

		}
		else
		{
			//search

		}
	}
	return 0;
}
int main()
{
	int c = hash_a(5000);
	hashTable<int> a;
	for (int i = 0; i < 100; i++)
	{
		a.insert(i);
		cout << "we are inseting " << i << " while size is " << a.getSize() << endl;
	}
	for (int i = 0; i < 100; i++)
	{
		a.deleteKey();
		cout << "we are deleting " << 100-i << " while size is " << a.getSize() << endl;
	}
	return 0;
}


//do we need to change a b p each time?
//count parameter 1 for each index? or the linked list size for each?
//how we know it is correct or not?
#include<iostream>
#include <cmath>
#include <ctime>
#include "HashTable.cpp"
using namespace std;

ll prime = pow(2, 61) - 1;
ll p = prime - 1;
ll a = rand() % p + 1;
ll b = rand() % prime;
ll m = 3;
hashTable<ll> table;

//returns the array of n distinct integers in range [1,2^w] generated randomly
ll* generateRandomKeys(ll n)
{
	ll* arr = new ll[n];
	srand(time(0));
	for (ll i = 0; i < n; i++)
	{
		ll x = pow(2, 64) - 1;
		ll k = rand() % x + 1;
		arr[i] = k;
	}
	return arr;
}
//takes a key value and hash it according to universal hash family: h(k) = ((ak + b) mod p) mod m
ll hashThisK(ll k, ll m)
{
	ll hk = (((a * k) + b) % prime) % m;
	return hk;
}

ll hashIt(ll* array,ll n)
{
	m = 3;
	for (ll i = 0; i < n; i++)
	{
		int op = (rand() % 3)+1;
		if (op == 1)
		{
			//insert
			if (table.insert(hashThisK(array[i], m), array[i])) //indexOfInsertion,valueOfKey
			{
				//rehash all
				cout << "resized" << endl;
				i = -1;
				table.clearTable();
				m = table.getSize();
			}

		}
		else if (op == 2)
		{
			//cout << "delete called" << endl;
			//delete
			//if (table.deleteKey())
			//{
			//	//rehash all
			//	i = 0;
			//	table.clearTable();
			//	m = table.getSize();
			//}

		}
		else
		{
			//cout << "search called" << endl;
			//search
			//ll searchIt = hashThisK(array[i], n);
		}
	}
	return 0;
}
int main()
{
	ll n;
	cout << "enter an integer n:";
	cin >> n;
	ll *arr = new ll[n];
	arr = generateRandomKeys(n);
	cout << "Keys are::" << endl;
	for (ll i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout<< endl;
	hashIt(arr, n);
	//int c = hash_a(5000);
	/*hashTable<ll> a;
	for (int i = 0; i < 100; i++)
	{
		a.insert(i);
		cout << "we are inseting " << i << " while size is " << a.getSize() << endl;
	}
	for (int i = 0; i < 100; i++)
	{
		a.deleteKey();
		cout << "we are deleting " << 100-i << " while size is " << a.getSize() << endl;
	}*/
	return 0;
}


//do we need to change a b p each time?
//count parameter 1 for each index? or the linked list size for each?
//how we know it is correct or not?


/*
int getM(int n)
{
	m = 3;
	cout << "n is" << n << endl;
	for (int i = 0; m < n; i++)
	{
		m = m * 2;
		cout << "m is " << m << endl;
	}
	cout << m;
	return m;
}
*/

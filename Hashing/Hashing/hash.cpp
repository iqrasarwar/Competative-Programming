#include<iostream>
#include <List>
#include <ctime>
#include "HashTable.h"
using namespace std;

ll prime = pow(2, 61) - 1;
ll p = prime - 1;
ll a = rand() % p + 1;
ll b = rand() % prime;
ll m = 3;
hashTable table;
 
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
	table.setParms(a, b, prime);
	for (ll i = 0; i < n; i++)
	{
		//cout << i;
		int op = (rand() % 3)+1;
		if (op == 1)
		{
			//insert
			if (table.insert(hashThisK(array[i], m), array[i])) //indexOfInsertion,valueOfKey
			{
				//cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! RESIZED !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			}

		}
		else if (op == 2)
		{
			//delete
			if (table.currCount() > 0)
			{
				int d = rand() % n;
				if (table.deleteKey(hashThisK(array[d], m), array[d])) //indexOfDeletion,valueOfKey
				{
					//cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! RESIZED !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
				}
			}
			else
			{
				//cout << "Hash table has no values to delete" << endl;
			}
		}
		else
		{
			//search
			if (table.currCount() > 0)
			{
				int d = rand() % n;
				table.searchVal(array[d]);
			}
			else
			{
				//cout << "Hash table has no values to Search" << endl;
			}
		}
	}
	table.printarr();
	table.printCollisions();
	return 0;
}
int main()
{
	cout << "\t\t----------------------------- HASHING WITH RESIZING --------------------------------------" << endl;
	ll n;
	cout << "Enter an integer n:";
	cin >> n;
	ll *arr = new ll[n];
	arr = generateRandomKeys(n);
	hashIt(arr, n);
	return 0;
}


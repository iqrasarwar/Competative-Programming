#pragma once
#include<iostream>
#include<list>
#include <stack>
using namespace std;
#define ll unsigned long long int
const ll S = 500;
bool isPrime(ll n) {
    for (ll i = 2; i <= n / i; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
ll getRandPrime()
{
    ll p = 0;
    do
    {
        p = rand() + pow(2,30);
    } while (!isPrime(p));
    return p;
}
class perfectHashTable
{
private:
    ll arr[S];
    ll a;
    ll b;
    ll p;
    ll prime;
public:
    perfectHashTable()
    {
        prime = getRandPrime();
        p = prime - 1; 
        for (ll i = 0; i < S; i++)
        {
            arr[i] = 0;
        }
        a = rand() % p + 1;
        b = rand() % prime;
    }
    void insert(ll index, ll value);
    ll printarr();
    void searchVal(ll value);
    void setParms(ll a, ll b, ll prime);
    ll hashThis(ll k);
};


void perfectHashTable::insert(ll index, ll value)
{
    ll newIndex = hashThis(value);
    if (arr[newIndex] == 0)
    {
        arr[newIndex] = value;
        return;
    }
    else
    {
        bool avoided = false;
        ll* temp = new ll[S];
        ll colliding = arr[newIndex];
        cout << "for index "<<newIndex<<" collision of " << value << " and " << colliding << " with a " << a << " b " << b << endl;
        for (ll i = 0; i < S; i++)
        {
            if (i != newIndex)
                temp[i] = arr[i];
            else
                temp[i] = 0;
            arr[i] = 0;
        }
        while (avoided == false)
        {
            prime = getRandPrime();
            a = rand() % p + 1;
            b = rand() % prime;
            ll thisIndex = hashThis(colliding);
            ll thisValue = hashThis(value);
            if (thisIndex == thisValue)
            {
                cout<< "for index " << thisIndex << " still collding with a " << a << " b " << b <<" and prime no "<<prime << endl;
                continue;
            }
            else
            {
                cout << "collision resolved!" << endl;
                arr[thisIndex] = colliding;
                arr[thisValue] = value;
                avoided = true;
            }
        }
        for (ll i = 0; i < S; i++)
        {
            if (temp[i] != 0)
                insert(index, temp[i]);
        }
        cout << "totally collision resolved!" << endl;
    }
}

ll perfectHashTable::printarr()
{
    ll j = 0;
    for (ll i = 0; i < S; i++)
    {
        if (arr[i] != 0) 
        {
            j++;
            
        }
        cout << arr[i] << "   ";
    }
    
    return j;
}

void perfectHashTable::searchVal(ll value)
{
    
}

ll perfectHashTable::hashThis(ll key)
{
    ll hk = (((a * key) + b) % prime) % S;
    return hk;
}


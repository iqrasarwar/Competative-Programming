#pragma once
#include<iostream>
#include<list>
#include <stack>
using namespace std;
#define ll unsigned long long int
const ll S = 5000;

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
        prime = pow(2, 61) - 1;
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
        int colliding = arr[newIndex];
        cout << "for index "<<newIndex<<" collision of " << value << " and " << colliding << " with a " << a << " b " << b << endl;
        for (int i = 0; i < S; i++)
        {
            if (i != newIndex)
                temp[i] = arr[i];
            else
                temp[i] = 0;
            arr[i] = 0;
        }
        while (avoided == false)
        {
            a = rand() % p + 1;
            b = rand() % prime;
            int thisIndex = hashThis(colliding);
            int thisValue = hashThis(value);
            if (thisIndex == thisValue)
            {
                cout<< "for index " << thisIndex << " still collding with a " << a << " b " << b << endl;
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
        for (int i = 0; i < S; i++)
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
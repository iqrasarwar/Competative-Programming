#pragma once
#include<iostream>
#include<list>
using namespace std;
#define ll unsigned long long int
typedef list<ll> IntList; // define IntList to be a std::list of int elements 

class hashTable
{
private:
    IntList* arr;
    ll size;
    ll currCunt;
    ll a;
    ll b;
    ll prime;
public:
    hashTable(ll s = 3)
    {
        a = 0, b = 0, prime = 0, currCunt = 0;
        size = s;
        arr = new IntList[size];
        for (ll i = 0; i < size; i++)
        {
            arr[i] = IntList();
        }
    }
    ~hashTable();
    ll getSize();
    bool deleteKey(ll index, ll value);
    ll currCount();
    bool isFull();
    bool isEmpty();
    bool insert(ll index, ll value);
    void printarr();
    void resize(ll newSize);
    void searchVal(ll value);
    void setParms(ll a,ll b,ll prime);
    ll hashThis(ll k, ll m);
};
#pragma once
#include<iostream>
using namespace std;
#define ll long long int

template <class t>
class hashTable
{
private:
    t* arr;
    ll size;
    ll currLoc;
public:
    hashTable(ll s = 3)
    {
        size = s;
        currLoc = -1;
        arr = new t[size];
    }
    hashTable(const hashTable& s);
    ~hashTable();
    ll getSize();
    bool deleteKey();
    t currLoc_();
    bool isFull();
    bool isEmpty();
    bool insert(ll index, t value);
    void printarr();
    void resize(ll newSize);
    void clearTable();
};
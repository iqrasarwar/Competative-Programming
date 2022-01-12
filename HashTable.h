#pragma once
#include<iostream>
using namespace std;

template <class t>
class hashTable
{
private:
    t* arr;
    int size;
    int currLoc;
public:
    hashTable(int s = 3)
    {
        size = s;
        currLoc = -1;
        arr = new t[size];
    }
    hashTable(const hashTable& s);
    ~hashTable();
    int getSize();
    t deleteKey();
    t currLoc_();
    bool isFull();
    bool isEmpty();
    void insert(t value);
    void printarr();
    void resize(int newSize);
};
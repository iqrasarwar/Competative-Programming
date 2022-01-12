#pragma once
#include "HashTable.h"

//copy constructor
template<class t>
hashTable<t>::hashTable(const hashTable& s)
{
    this->size = s.size;
    this->currLoc = -1;
    arr = new t[size];
    for (int i = 0; i < size; i++)
    {
        if (!isFull())
            arr[++currLoc] = s.arr[i];
    }
}
//destructor
template<class t>
hashTable<t>::~hashTable()
{
    if (arr != nullptr)
        delete[] arr;
}
template<class t>
int hashTable<t>::getSize()
{
    return size;
}
//returns currLoc of arr value and dec pointer
template<class t>
t hashTable<t>::deleteKey()
{
    if (isFull())
        this->resize(this->size * 2);
    if (this->currLoc <= (this->size / 4))
        this->resize(this->size / 2);
    if (!isEmpty())
        return arr[currLoc--];
    else
    {
        currLoc = -1;
        return -1;
    }
}
//return value at currLoc of arr
template<class t>
t hashTable<t>::currLoc_()
{
    return arr[currLoc];
}
//return true if arr is full
template<class t>
bool hashTable<t>::isFull()
{
    return currLoc == size - 1;
}
//return true if arr is empty
template<class t>
bool hashTable<t>::isEmpty()
{
    return currLoc == -1;
}
template<class t>
//inc pointer and insert value at currLoc of arr
void hashTable<t>::insert(t value)
{
    if (isFull())
        this->resize(this->size * 2);
    if (this->currLoc <= (this->size / 4) && currLoc > 0)
        this->resize(this->size / 2);
    if (!isFull())
        arr[++currLoc] = value;
}
template<class t>
//print the values inserted in arr till currLoc 
void hashTable<t>::printarr()
{
    cout << "\nTable is::";
    for (int i = currLoc; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
template<class t>
//manage size
//if 1/4 of arr is empty reduces its size by half
//if arr is full double its size
void hashTable<t>::resize(int newSize) //here size must be size*size or size/4
{
    t* temp = new t[currLoc + 1];
    for (int i = 0; i <= currLoc; i++)
    {
        temp[i] = arr[i];
    }
    if (arr != NULL)
        delete[] arr;
    this->size = newSize;
    this->arr = new t[size];
    for (int i = 0; i <= currLoc; i++)
    {
        arr[i] = temp[i];
    }
}
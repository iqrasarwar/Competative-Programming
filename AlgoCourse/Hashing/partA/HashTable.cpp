#pragma once
#include "HashTable.h"
#define ll unsigned long long int

//destructor

void hashTable::printCollisions()
{
    cout << "\t\t--------------------------------------- COLLISIONS --------------------------------------" << endl;
    cout << "Collisions at each index::" << endl;
    ll j = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].size() > 1)
        {
            int c = arr[i].size() - 1;
            cout << "Index # " << i << " :: " << c << endl;
            j += c;
        }
        else
        {
            cout << "Index # " << i << " :: " << 0 << endl;
        }
    }
    cout << "TOTAL COLLISIONS :: " << j << endl;
}

hashTable::~hashTable()
{
    if (arr != nullptr)
        delete[] arr;
}

ll hashTable::getSize()
{
    return size;
}
//returns currCunt of arr value and dec pointer
bool hashTable::deleteKey(ll index,ll value)
{
    bool reSized = false;
    if (this->currCunt <= (this->size / 4))
    {
        this->resize(this->size / 2);
        reSized = true;
    }
    if (!isEmpty())
    {
        bool toDel = false;
        IntList listt = arr[index];
        IntList::iterator itr = listt.begin();
        for (; itr != listt.end(); itr++)
        {
            if (value == *itr)
            {
                currCunt--;
                arr[index].remove(value);
                toDel = true;
                cout << "Key " << value << " deleted from index " << index << endl;
            }
        }

        if (toDel == false)
        {
           // cout << "Key " << value << " not found to be deleted!" << endl;
        }
    }
    else
       currCunt = 0;
    return reSized;
}
//return value at currCunt of arr
ll hashTable::currCount()
{
    return currCunt;
}
//return true if arr is full
bool hashTable::isFull()
{
    return currCunt == size;
}
//return true if arr is empty
bool hashTable::isEmpty()
{
    return currCunt == 0;
}
//inc pointer and insert value at currCunt of arr
bool hashTable::insert(ll index, ll value)
{
    bool reSized = false;
    if (isFull())
    {
        this->resize(this->size * 2);
        reSized = true;
    }
    if (!isFull())
    {
        //cout << "Key " << value << " hashed & inserted to index " << index << endl;
        currCunt++;
        arr[index].push_back(value);
    }
    return reSized;
}
 
//print the values inserted in arr till currCunt 
void hashTable::printarr()
{
    cout << "\n\t\t---------------------------------- HASH TABLE ----------------------------------------\n" << endl;
    int j = 0;

    for (ll i = 0; i < size; i++)
    {
        cout << i << ":: ";
        IntList::iterator itr = arr[i].begin();
        for (; itr != arr[i].end(); itr++)
        {
            j++;
            cout << *itr << "\t";
        }
        cout << endl;
    }
    cout << j << endl;
}
 
//manage size
//if 1/4 of arr is empty reduces its size by half
//if arr is full double its size
void hashTable::resize(ll newSize) //here size must be size*size or size/4
{
    ll* tempArr = new ll[currCunt];
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        IntList::iterator itr = arr[i].begin();
        for (; itr != arr[i].end(); itr++,j++)
        {
            if (*itr != 0)
                tempArr[j] = *itr;
        }
    }
    if (arr != NULL)
       delete[] arr;
    this->size = newSize; 
    arr = new IntList[size];
    int x = currCunt;
    currCunt = 0;
    for (int i = 0; i < x; i++)
    {
        ll index = hashThis(tempArr[i], newSize);
        insert(index, tempArr[i]);
    }
}
 
void hashTable::searchVal(ll value)
{
    bool found = false;
   // cout << "Searching " << value << " in hash table:";
    ll index = hashThis(value, size);
    IntList listt = arr[index];
    IntList::iterator itr = listt.begin();
    for (; itr != listt.end(); itr++)
    {
        if (value == *itr)
        {
             found = true;
             cout << "Found at index " << index << " as " << *itr << endl;
        }
    }
    if (found == false)
    {
       // cout << "Not found!" << endl;
    }
}

void hashTable::setParms(ll a, ll b, ll prime)
{
    this->a = a;
    this->b = b;
    this->prime = prime;
}

ll hashTable::hashThis(ll k, ll m)
{
    ll hk = (((a * k) + b) % prime) % m;
    return hk;
}
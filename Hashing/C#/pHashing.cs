using System;
namespace PerfectHashing
{
    public class pHashing
    {
        bool isPrime(ulong n)
        {
            for (ulong i = 2; i <= n / i; ++i)
            {
                if (n % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
        ulong getRandPrime()
        {
            ulong p = 0;
            Random rnd = new Random();
            int num = rnd.Next();
            do
            {
                p = (ulong)(rnd.Next() + Math.Pow(2, 30));
            } while (!isPrime(p));
            return p;
        }
        ulong S;
        ulong[] arr;
        ulong a { get; set; }
        ulong b { get; set; }
        ulong p { get; set; }
        ulong prime { get; set; }
        public ulong currCount { get; set; }
        public ulong randomTries { get; set; }
        public pHashing()
        {
            S = 7000;
            arr = new ulong[S];
            Random rnd = new Random();
            prime = (ulong)(Math.Pow(2, 61) - 1);
            p = prime - 1;
            for (ulong i = 0; i < S; i++)
            {
                arr[i] = 0;
            }
            a = (ulong)rnd.Next() % (p) + 1;
            b = (ulong)rnd.Next() % prime;
            randomTries = 0;
        }
        //return true if arr is full
        bool isFull()
        {
            return currCount == S;
        }
        public void insert(ulong value)
        {
            if (isFull())
                resize(S * 2);
            if (!isFull())
            {
                ulong newIndex = hashThis(value);
                if (arr[newIndex] == 0)
                {
                    currCount++;
                    arr[newIndex] = value;
                    return;
                }
                else
                {
                    bool avoided = false;
                    ulong size = S;
                    ulong[] temp = new ulong[size];
                    ulong colliding = arr[newIndex];
                    Console.WriteLine("for index " + newIndex + " collision of " + value + " and " + colliding + " with a " + a + " b " + b);
                    for (ulong i = 0; i < S; i++)
                    {
                        if (i != newIndex)
                            temp[i] = arr[i];
                        else
                            temp[i] = 0;
                        arr[i] = 0;
                    }
                    while (avoided == false)
                    {
                        randomTries++;
                        Random rnd = new Random();
                        prime = getRandPrime();
                        a = (ulong)rnd.Next() % p + 1;
                        b = (ulong)rnd.Next() % prime;
                        ulong thisIndex = hashThis(colliding);
                        ulong thisValue = hashThis(value);
                        if (thisIndex == thisValue)
                        {
                            Console.WriteLine("for index " + thisIndex + " still collding with a " + a + " b " + b + " and prime no " + prime);
                            continue;
                        }
                        else
                        {
                            Console.WriteLine("collision resolved!");
                            arr[thisIndex] = colliding;
                            arr[thisValue] = value;
                            currCount = 2;
                            avoided = true;
                        }
                    }
                    for (ulong i = 0; i < size; i++)
                    {
                        if (temp[i] != 0)
                            insert(temp[i]);
                    }
                    Console.WriteLine("totally collision resolved!");
                }
            }
        }
        public ulong printarr()
        {
            ulong j = 0;
            for (ulong i = 0; i < S; i++)
            {
                if (arr[i] != 0)
                {
                    j++;
                    Console.Write(arr[i] + "   ");
                }
            }

            return j;
        }
        public void searchVal(ulong value)
        {
            if (arr[hashThis(value)] == value)
                Console.WriteLine("Found on index " + hashThis(value));
            else
                Console.WriteLine("Not found");
        }
        public ulong hashThis(ulong key)
        {
            ulong hk = ((a * key) + b) % prime % S;
            return hk;
        }
        void resize(ulong newSize) //here size must be size*size or size/4
        {
            Console.WriteLine("RESIZING");
            ulong[] tempArr = new ulong[currCount];
            for (ulong i = 0; i < currCount; i++)
            {
                if (arr[i] != 0)
                    tempArr[i] = arr[i];
            }
            S = newSize;
            arr = new ulong[S];
            ulong x = currCount;
            currCount = 0;
            for (ulong i = 0; i < x; i++)
                insert(tempArr[i]);
        }

    }
}

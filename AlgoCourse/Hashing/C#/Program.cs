using System;
namespace PerfectHashing
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("\t\t--------------------------------- PERFECT HASHING --------------------------------");
            Console.WriteLine("Enter size of Data you want to hash:: ");
            ulong n = (ulong)Convert.ToInt64(Console.ReadLine());

            Random rnd = new Random();
            ulong prime = (ulong)Math.Pow(2, 61) - 1;
            ulong p = prime - 1;
            ulong a = (ulong)rnd.Next() % p + 1;
            ulong b = (ulong)rnd.Next() % prime;
            pHashing[] table = new pHashing[n];
            ulong[] value = new ulong[n];

            for (ulong i = 0; i < n; i++)
            {
                table[i] = new pHashing();
            }

            for (ulong j = 0; j < n; j++)
            {
                value[j] = (ulong)rnd.Next();
                ulong index = hashThisK(value[j], n, a, b, prime);
                table[index].insert(value[j]);
            }
            ulong x = 0;
            Console.WriteLine("\t\t------------PERFECT HASH TABLE-------------");
            for (ulong j = 0; j < n; j++)
            {
                Console.Write(j + "::");
                x += table[j].printarr();
                //ulong index = hashThisK(value[j], n, a, b, prime);
                //table[index].searchVal(value[j]);
                Console.WriteLine();
            }
            x = 0;
            Console.WriteLine("\t\t------------RANDOM TRIES-------------");
            for (ulong j = 0; j < n; j++)
            {
                x += table[j].randomTries;
                Console.WriteLine("Slot# " + j + " random tries are :: " + table[j].randomTries);
            }
            Console.WriteLine("Total random tries are :: " + x);

        }
        public static ulong hashThisK(ulong k, ulong m, ulong a, ulong b, ulong prime)
        {
            ulong hk = (((a * k) + b) % prime) % m;
            return hk;
        }

    }
}

//using System;

//namespace ConsoleApp10
//{
//    class PerfectHashTable
//    {
//        ulong[] ai;
//        ulong size;
//        ulong a, b, p, tries;

//        public PerfectHashTable(ulong n)
//        {
//            size = 0;
//            //m = n;                          //equal to data size
//            p = (ulong)(Math.Pow(2, 61) - 1);
//            ai = new ulong[size];
//            for (ulong i = 0; i < size; i++)
//            {
//                //Console.WriteLine(ai[i]);
//                ai[i] = new ulong();
//                ai[i] = 0;                      //initializing with -1
//            }
//            a = generateA();
//            b = generateB();
//            tries = 0;
//        }
//        public ulong getIndex(ulong k)
//        {
//            ulong index = (((a * k) + b) % p) % size;
//            return index;
//        }
//        ulong generateA()
//        {
//            Random rnd = new Random();
//            ulong a = ((ulong)rnd.Next() % p) + 1;             // a in [1,p-1]
//            if (a == p)
//            {
//                a -= 1;
//            }
//            return a;
//        }
//        ulong generateB()
//        {
//            Random rnd = new Random();
//            ulong b = (ulong)rnd.Next() % p;             //b is chosen randomly in the range [0, p − 1]
//            return b;
//        }
//        bool already(ulong index)
//        {
//            for (ulong i = 0; i < size; i++)
//            {
//                //Console.WriteLine(ai[i]);
//                if (ai[index] > 0)
//                {
//                    return true;
//                }
//            }
//            return false;
//        }
//        public void hashValue(ulong k)
//        {
//            ulong[] temp = new ulong[size];
//            for (ulong i = 0; i < size; i++)
//            {
//                //Console.WriteLine(ai[i]);
//                temp[i] = new ulong();
//                temp[i] = ai[i];                      //initializing with -1
//            }
//            ai = new ulong[size + 1];
//            for (ulong i = 0; i < size; i++)
//            {
//                //Console.WriteLine(ai[i]);
//                ai[i] = new ulong();
//                ai[i] = temp[i];                      //initializing with -1
//            }
//            size = size + 1;

//            ulong index = getIndex(k);
//            Console.WriteLine("index is " + index);
//            /*Console.WriteLine("index is " + index);
//			Console.WriteLine("a= " + a + "\n");
//			Console.WriteLine("b= " + b + "\n");*/
//            while (already(index))
//            {
//                Console.WriteLine("---collision---");
//                rehashing();
//                index = getIndex(k);
//                Console.WriteLine("index generated " + index);
//                /*Console.WriteLine("after index is " + index);
//				Console.WriteLine("a= " + a + "\n");
//				Console.WriteLine("b= " + b + "\n");*/
//            }
//            ai[index] = k;

//            Console.WriteLine("Tries for key " + k + " are " + tries);
//            tries = 0;
//        }
//        public bool isPrime(ulong x)
//        {
//            for (ulong i = 2; i <= x / i; ++i)          //got from net
//            {
//                if (x % i == 0)
//                {
//                    return false;
//                }
//            }
//            return true;
//        }
//        void rehashing()
//        {
//            //Console.WriteLine("rehashing");

//            Random rnd = new Random();

//            ulong cnt = 0;
//            ulong[] temp = new ulong[size];
//            for (ulong i = 0; i < size; i++)
//            {
//                temp[i] = new ulong();
//                if (ai[i] != 0)
//                {
//                    temp[cnt] = ai[i];
//                    cnt++;
//                }
//                //Console.WriteLine("temp[i] " + temp[i]);
//                //ai[i] = 0;                      //initializing with -1
//            }
//            ulong c = cnt;
//            while (cnt != 0)
//            {
//                cnt = c;
//                while (!isPrime(p))
//                {
//                    p = 1073741824 + (ulong)rnd.Next();     //1073741824=2^30
//                }                         //new random prime number assigned

//                //Console.WriteLine("pa pb " + a + " " + b);
//                a = generateA();
//                b = generateB();
//                //Console.WriteLine("a b " + a + " " + b);
//                ai = new ulong[size];
//                for (ulong i = 0; i < size; i++)
//                {
//                    ai[i] = new ulong();
//                    ai[i] = 0;                      //initializing with 0
//                }
//                for (ulong i = 0; i < cnt; i++)
//                {
//                    ulong index = getIndex(temp[i]);
//                    //Console.WriteLine("INdex= " + index + " \n");
//                    //Console.WriteLine("temp= " + temp[i] + " \n");
//                    ulong x = temp[i];
//                    ai[index] = x;
//                    //Console.WriteLine("AI= " + ai[index] + " \n");
//                }
//                ulong ail = getLength(ai);
//                ulong templ = getLength(temp);
//                //Console.WriteLine("temp length " + templ);
//                //Console.WriteLine("ai length " + ail);
//                for (ulong i = 0; i < size; i++)
//                {
//                    if (ai[i] != 0)
//                    {
//                        cnt--;
//                    }
//                }
//                //printArray();
//                tries++;
//                p = 4;
//            }
//        }
//        public ulong getTries()
//        {
//            return tries;
//        }
//        public ulong getLength(ulong[] arrr)
//        {
//            ulong count = 0;
//            for (ulong i = 0; i < size; i++)
//            {
//                if (arrr[i] > 0)
//                {
//                    count += 1;
//                }
//            }
//            return count;
//        }
//        public void printArray()
//        {
//            for (ulong i = 0; i < size; i++)
//            {
//                Console.Write(ai[i] + ", ");
//            }
//        }

//    }
//    class TwoLevelHashing
//    {
//        ulong m, a, b, p;
//        PerfectHashTable[] htp;          //declared an array = data size

//        public TwoLevelHashing(ulong n)
//        {
//            m = n;
//            p = (ulong)(Math.Pow(2, 61) - 1);
//            a = generateA();
//            b = generateB();
//            htp = new PerfectHashTable[m];              //an array containing addresses of phtables
//            for (ulong i = 0; i < m; i++)
//            {
//                htp[i] = new PerfectHashTable(n);
//            }
//        }
//        public void hashValue(ulong k)
//        {
//            ulong index = getIndex(k);
//            //Console.WriteLine("index got " + index);
//            htp[index].hashValue(k);            //hash value inside the selected table
//        }
//        public ulong getIndex(ulong k)
//        {
//            ulong index = (((a * k) + b) % p) % m;
//            return index;
//        }
//        ulong generateA()
//        {
//            Random rnd = new Random();
//            ulong a = ((ulong)rnd.Next() % p) + 1;             // a in [1,p-1]
//            if (a == p)
//            {
//                a -= 1;
//            }
//            return a;
//        }
//        ulong generateB()
//        {
//            Random rnd = new Random();
//            ulong b = (ulong)rnd.Next() % p;             //b is chosen randomly in the range [0, p − 1]
//            return b;
//        }
//        public void seeTwoLevel()
//        {
//            for (ulong i = 0; i < m; i++)
//            {
//                Console.Write(i + "| ");
//                htp[i].printArray();
//                Console.WriteLine();
//            }
//        }
//    }

//    class Program
//    {
//        static ulong[] generateRandomKeys(ulong[] arr, ulong n)
//        {
//            ulong po = (ulong)Math.Pow(2, 64) - 1;          //-1 bcz number starts with zero
//            Random rnd = new Random();
//            Console.WriteLine(po);
//            for (ulong i = 0; i < n; i++)
//            {
//                ulong random = ((ulong)rnd.Next() % po) + 1;
//                if (random == 0)
//                {
//                    random += 1;                //do not create zero as random number
//                }
//                Console.WriteLine("Roandom number is: " + random);
//                if (i > 0)
//                {
//                    if (arr[i - 1] == random)
//                    {
//                        i--;
//                    }
//                    else
//                    {
//                        arr[i] = random;
//                    }
//                }
//                else
//                {
//                    arr[i] = random;
//                }
//            }
//            return arr;
//        }
//        static void Main(string[] args)
//        {
//            /*Console.WriteLine((ulong)Math.Pow(2, 61) - 1);
//			Console.WriteLine((ulong)Math.Pow(2, 61) - 31);
//			Console.WriteLine((ulong)Math.Pow(2, 61) - 45);
//			Console.WriteLine((ulong)Math.Pow(2, 62) - 57);
//			Console.WriteLine((ulong)Math.Pow(2, 62) - 87);

//			Console.WriteLine((ulong)Math.Pow(2, 63) - 25);
//			Console.WriteLine((ulong)Math.Pow(2, 63) - 165);
//			Console.WriteLine((ulong)Math.Pow(2, 64) - 59);
//			Console.WriteLine((ulong)Math.Pow(2, 64) - 83);
//			Console.WriteLine((ulong)Math.Pow(2, 64) - 95);
//*/
//            ulong n = 40000;
//            ulong[] keys = new ulong[n];
//            for (ulong i = 0; i < n; i++)
//            {
//                keys[i] = new ulong();
//            }
//            keys = generateRandomKeys(keys, n);
//            for (ulong i = 0; i < n; i++)
//            {
//                //Console.WriteLine(keys[i]);
//            }

//            //--------- 2 level hashing-------
//            TwoLevelHashing tlh = new TwoLevelHashing(n);
//            for (ulong i = 0; i < n; i++)
//            {
//                ulong k = keys[i];
//                Console.WriteLine("\n----------------------------------\nkey is " + k);
//                tlh.hashValue(k);
//                //tlh.seeTwoLevel();
//            }

//            tlh.seeTwoLevel();
//        }
//    }
//}

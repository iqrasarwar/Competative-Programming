using System;
namespace PerfectHashing
{
	class Program
	{
		static void Main(string[] args)
		{
			Random rnd = new Random();
			ulong prime = (ulong)Math.Pow(2, 61) - 1;
			ulong p = prime - 1;
			ulong a = (ulong)rnd.Next() % p + 1;
			ulong b = (ulong)rnd.Next() % prime;
			ulong n = 5000;
			pHashing[] table = new pHashing[n];
			for(ulong i = 0; i < n; i++)
            {
				table[i] = new pHashing(n);
            }
			//int xx = 0;
			ulong[] value = new ulong[n];
			for (ulong j = 0; j < n; j++)
			{
				value[j] = (ulong)rnd.Next();
				ulong index = hashThisK(value[j], n, a, b, prime);
				table[index].insert(index, value[j]);
			}
			ulong x = 0;
			for (ulong j = 0; j < n; j++)
			{
				Console.Write(j + "::");
				//x += table[j].printarr();
				ulong index = hashThisK(value[j], n, a, b, prime);
				table[index].searchVal(value[j]);
			}
			Console.WriteLine(x);
		}
		public static ulong hashThisK(ulong k, ulong m, ulong a, ulong b, ulong prime)
		{
			ulong hk = (((a * k) + b) % prime) % m;
			return hk;
		}

	}
}

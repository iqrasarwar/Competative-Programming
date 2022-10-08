#include <iostream>
#include<string>
using namespace std;

int main() {
	int t = 0;
	cin >> t;
	while (t--)
	{
		int size;
		cin >> size;
		string s;
		cin >> s;
		string tt = "";
		if (s.length() == 2)
			tt = s;
		else
		{
			int last = s.length() - 1;
			int l = size / 2;
			if (size % 2 != 0)
				l++;
			for (int i = 0; i < l; i++)
			{
				tt = (s[i] + tt) < (tt + s[i]) ? (s[i] + tt) : (tt + s[i]);
				if (last > i)
				{
					tt = (s[last] + tt) < (tt + s[last]) ? (tt + s[last]) : (s[last] + tt);
					last--;
				}
			}
		}

		cout << tt << endl;
	}
	return 0;
}

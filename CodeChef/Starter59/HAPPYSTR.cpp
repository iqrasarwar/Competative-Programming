#include <iostream>
using namespace std;

bool isVowel(char c)
{

	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}
int main() {
	int t =0;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		bool happy = false;
		for (int i = 0; i < s.length(); i++)
		{
			if (i + 2 < s.length() && isVowel(s[i]) && isVowel(s[i + 1]) && isVowel(s[i + 2]) )
				happy = true;
		}
		if (happy)
		{
			cout << "Happy" << endl;
		}
		else
		cout << "Sad" << endl;
	}
	return 0;
}

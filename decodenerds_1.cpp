// decodenerds_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int jane = 0;
    int tane = 0;
    for (int i = 0; i < s.length(); i++)
        s = tolower(s[i]);
    while (s.length())
    {
        if (s.length() >= 2)
        {
            if (s[0] < s[s.length()])
            {
                jane += (26 - (s[0] - 97));
                tane += (26 - (s[s.length()] - 97));
            }
            else
            {
                jane += (26 - (s[s.length()] - 97));
                tane += (26 - (s[0] - 97));
            }
            s = s.substr(1, s.length() - 2);
        }
        else
        {
            tane += (26 - (s[0] - 97));
            s = "";
        }
    }
    cout << jane << endl;
    return 0;
}

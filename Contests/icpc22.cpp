#include <iostream>
#include <string>
#include<unordered_map>
#include <vector>
using namespace std;

vector<pair<char,char>> vis;

bool mappp(char key, char target, unordered_map<char,char> m)
{
    if (m.find(key) != m.end())
    {
        if (m[key] == target)
            return true;
        else
        {
            vis.push_back({ key,m[key] });
            for (int i = 0; i < vis.size(); i++)
            {
                if (vis[i].first == key && vis[i].second == m[key])
                {
                    vis.clear();
                    return false;
                }
            }
            
                mappp(m[key], target, m);
           
        }
    }
    else
    {
        vis.clear();
        return false;
    }
}
int main() {
    int nn;
    cin >> nn;
    while (nn--)
    {
        string map, eq, s1, s2;
        int i, N, counter;
        bool isEQ;
        vector <char> map_arr, eq_arr;
        vector <string> str1, str2;
        char c;
        cin >> c;
        vector<char> temp;
        while (!isdigit(c))
        {
            temp.push_back(c);
            cin >> c;
        }
        N = int(c) - 48;
        for (int i = 0; i < temp.size()/ 2; i++)
        {
            map_arr.push_back(temp[i]);
        }
        for (int i = temp.size() / 2; i < temp.size(); i++)
        {
            eq_arr.push_back(temp[i]);
        }
        for (counter = 0; counter < N; counter++) {
            cin >> s1 >> s2;
            str1.push_back(s1);
            str2.push_back(s2);
        }
        unordered_map<char, char> mapp;
        for (int i = 0; i < temp.size()/2; i++)
        {
            mapp.insert(std::make_pair(map_arr[i], eq_arr[i]));
        }
        for (counter = 0; counter < N; counter++) {
            s1 = str1[counter];
            s2 = str2[counter];
            for (i = 0; i < s1.length(); i++) {
                if (s1[i] == s2[i]) isEQ = false;
                else {
                    if (mappp(s1[i], s2[i], mapp))
                        isEQ = true;
                    else
                    {
                        isEQ = false;
                        break;
                    }
                }
            }
            if (s1.length() < 3 or s1.length() > 20) isEQ = false;
            else if (s1.length() != s2.length()) isEQ = false;
            else if (s1 == s2) isEQ = true;
            if (isEQ) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}
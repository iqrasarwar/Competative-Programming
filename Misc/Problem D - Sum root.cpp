#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<string> sum;
vector<int> vv;

void fun(string o,string s, int i,int j)
{
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    if (l > j)
    {
        sum.push_back(s);
        return;
    }
    if (r > j)
    {
        sum.push_back(s);
        return;
    }
    string t1 = s;
    t1 += o[l];
    string t2 = s;
    t2 += o[r];
    fun(o,t1,l,j);
    fun(o,t2,r,j);
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        string ss;
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            if (s[i] != ' ')
                ss += s[i];
        }
        string z = "";
        z += ss[0];
        fun(ss,z, 0,ss.size());
        int c = 0;
        int zsum = sum.size();
        for (int i = 0; i < zsum; i++)
        {
            c += stoi(sum[i]);
        }
        vv.push_back(c);
        sum.clear();
    }
    int zzsum = vv.size();
    for (int i = 0; i < zzsum; i++)
    {
        cout << vv[i] << endl;
    }
}

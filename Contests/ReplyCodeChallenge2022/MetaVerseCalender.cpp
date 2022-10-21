//Problem#01
#include <iostream>

using namespace std;

int main() 
{
    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int val[6];
        int** arr = new int*[6];
        for (int i = 0; i < 6; i++)
        {
            arr[i]= new int[1000000];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j ++)
            {
                arr[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cin >> val[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j += val[i])
            {
                arr[i][j] = 1;
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            bool addDay = true;
            for (int j = 0; j < n; j++)
            {
                if (arr[j][i] == 0)
                    addDay = false;
            }
            if (addDay == true)
                count++;
        }
        cout << "Case #" <<i << ": "<<count << endl;
        i++;
    }
    return 0;
}

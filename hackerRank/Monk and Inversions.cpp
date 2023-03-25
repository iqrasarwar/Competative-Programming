#include <iostream>
#include<vector>
using namespace std;

int main() {
	int num;
	cin >> num;
	while(num--)
	{
		int n;
		cin>>n;
		vector<vector<int>> v(n, vector<int>(n, 0));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>v[i][j];
			}
		}
		int p =0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				int z = v[i][j];
				for(int k=i;k<n;k++)
				{
					for(int l=j;l<n;l++)
					{
						if(z > v[k][l])
						p++;
					}
				}
			}
		}
		cout<<p<<endl;
	}
}

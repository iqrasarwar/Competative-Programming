#include <iostream>
using namespace std;

int main() {
 int t;
 cin>>t;
 while(t--)
 {
     int a,b;
     cin>>a>>b;
     cout<<a-b<<endl;
 }
	return 0;
}

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int a,b;
	    cin>>a>>b;
	    cout<<(a*2)+(b*4)<<endl;
	}
	return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,x;
	    cin>>n>>x;
	    int v[100001];
	    for (int i = 0; i < n; i++) {
	        cin>>v[i];
	      }
	      reverse(v,v+n);
	    int xx=n;
	    for (int i =0;i<n;i++) {
	       if(v[i]>=x)
	        continue;
	        else
	        {
	            xx=i;
	            break;
	        }
	    }
	    cout<<n-xx<<endl;
	}
	return 0;
}
#include <iostream>
#include<map>
#include<math.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s;
	    cin>>s;
	     map<char , int >m;
	     int sum=0;
          for(long i=0;i<s.length();)
          {
              if(i+1<n && s[i]==s[i+1])
              {
                  sum++;i+=2;
                  
              }
              else
              {
                  sum++;i++;
              }
          }
            cout<<sum<<endl;
	}
	return 0;
}

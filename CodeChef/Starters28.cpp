Problem: SELFDEF

#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,a=0,c=0;
	    cin>>n;
	    for (int i = 0; i < n; i++){
	        cin>>a;
	        if(a>=10 && a<=60)
	            c++;
	    }
	    
	    cout<<c<<endl;
	}
	return 0;
}

Problem: SUNDAY

#include <iostream>
using namespace std;

int main() {
	int sat[4]={6,13,20,27};
	int sun[4]={7,14,21,28};
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[30];
	    int vac = 8 +n;
	    for (int i=0 ;i<n;i++) 
	    {
	        cin>>arr[i];
	        for(int ji=0;ji<4;ji++)
    	    {
    	        if(arr[i] == sat[ji])
    	        vac--;
    	        if(arr[i] == sun[ji])
    	        vac--;
    	    }
	    }
	    cout<<vac<<endl;
	}
	return 0;
}

Problem: CARCHOICE
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    float one,two,three,four;
	    cin>>one>>two>>three>>four;
	    float a=three/one;
	    float b=four/two;
	    if(a<b)
	    {
	        cout<<-1<<endl;
	    }
	    else if(a>b)
	    {
	        cout<<1<<endl;
	    }
	    else
	    cout<<0<<endl;
	}
	return 0;
}

Problem: PERMXORITY 
#include <iostream>
#include<vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	   vector<int> v;
	   int n;
	   cin>>n;
       if(n%2!=0)
	   {
	       for (int i =0; i<n; i++) 
	       cout<<i+1<<" ";
    	   cout<<endl;
	   }
	   else
	   {
	       if(n==2)
	        cout<<-1<<endl;
	       else if(n==4)
	        cout<<1<<" "<<4<<" "<<" "<<2<<" "<<3<<endl;
	       else if(n>4)
	       {
	           int i=0;
	           for(;i<n-4;i+=1)
    	       {
    	           cout<<i+1<<" ";
    	       }
    	       cout<<i+3<<" "<<i+4<<" "<<i+2<<" "<<i+1<<endl;
	       }
	   }
	   
	}
	return 0;
}


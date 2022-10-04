#include <iostream>
using namespace std;

int main() {
	double t;
	cin>>t;
	while(t--)
	{
	    double x=0,y=0;
	    cin>>x>>y;
	    double prob = 6 - (x+y);
	    if(prob < 0) 
	        prob =0;
	   double p = prob/6;
	    cout<<p<<endl;
	}
	return 0;
}

Have the function MathChallenge(str) take the str parameter being passed and determine if there is some substring K that can be repeated N > 1 times to produce the input string exactly as it appears. Your program should return the longest substring K, and if there is none it should return the string -1.

For example: if str is "abcababcababcab" then your program should return abcab because that is the longest substring that is repeated 3 times to create the final string. Another example: if str is "abababababab" then your program should return ababab because it is the longest substring. If the input string contains only a single character, your program should return the string -1.









#include <iostream>
#include <string>
using namespace std;

string MathChallenge(string str) {
  int n = str.length();
  for(int l=n/2;l>= 1;l--)
  {
    if(n%l == 0)
    {
      string thisStr = str.substr(0,l);
      int i = 0;
      for(i = l; i+l<=n;i+=l)
      {
        string next = str.substr(i,l);
        if(thisStr != next)
        {
          break;
        }
      }
      if(i == n)
      {
        return thisStr;
      }
    }
  }
  return "-1";
}

int main(void) { 
   
  // keep this function call here
  cout << MathChallenge(coderbyteInternalStdinFunction(stdin));
  return 0;
    
}

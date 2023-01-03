class Solution {
public:
    bool isPalindrome(int x) {
        //if(x<0) x*=-1;
        string s = to_string(x);
        int size = s.length();
        int xx = size - 1;
        for(int i=0;i<size/2;i++)
        {
            if(s[i] != s[xx])
                return false;
            xx--;
        }
        return true;
    }
};

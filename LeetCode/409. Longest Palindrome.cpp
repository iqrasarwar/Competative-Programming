class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> M;
        for(auto &i: s){
            M[i-'a']++;
        }
        bool one = false;
        int length = 0;
        for (auto const& x : M)
        {
            if (x.second % 2 == 0)
            {
                length+=x.second;
            }
            else 
            {
                one = true;
                length+=(x.second-1);
            }
        }
        if(one) ++length;
        return length;
    }
};

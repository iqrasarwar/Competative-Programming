class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            bool t = true;
            string s = words[i];
            int size = s.length();
            int xx = size - 1;
            for(int i=0;i<size/2;i++)
            {
                if(s[i] != s[xx])
                    t = false;
                xx--;
            }
            if(t)
            return s;
        }
        return "";
    }
};

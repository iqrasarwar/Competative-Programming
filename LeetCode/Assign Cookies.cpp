class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        // int content = accumulate(s.begin(),s.end(),0);
        int gc = 0, sc =0;
        int c =0;
        while(gc < g.size() && sc < s.size())
        {
            if(g[gc] <= s[sc])
            {
                c++;
                gc++;
                sc++;
            }
            else 
            sc++;
        }
        return c;
    }
};
//https://leetcode.com/submissions/detail/1133901078/

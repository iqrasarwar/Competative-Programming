class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> m;
        vector<vector<int>> ans;
        for(auto n : nums) {
            m[n] = ++m[n];
            while(ans.size()<m[n])
                ans.push_back(vector<int>());
            ans[m[n]-1].push_back(n);
        }
        return ans;
    }
};

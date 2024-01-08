class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size();

        vector<unordered_map<long long int,int>> dp(n);

        int res = 0;
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                long long int diff = 1ll*arr[i]-arr[j];
                if(diff <= INT_MIN || diff >= INT_MAX) continue;

                int seq = 0;
                if(dp[j].find(diff) != dp[j].end()) seq = dp[j][diff];

                dp[i][diff] += seq + 1;
                res += seq;
            }
        }
        return res;
    }
};

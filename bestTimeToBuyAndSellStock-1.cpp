class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_p = prices[0];
        int max_ = -1;
        for(int i =0;i<prices.size();i++)
        {
            min_p = min(prices[i],min_p);
            max_ = max(max_, prices[i]-min_p);
        }
        return max_;
    }
};

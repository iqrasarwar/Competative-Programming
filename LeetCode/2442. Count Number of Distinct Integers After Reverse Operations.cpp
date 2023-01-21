class Solution {
public:
    int reverse(int num)
    {
        int reversed = 0;
        while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
        }
        return reversed;
    }
    int countDistinctIntegers(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            int x = reverse(nums[i]);
            m[x]++;
        }
        return m.size();
    }
};

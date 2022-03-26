class Solution {
public:
    int findGCD(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int s = nums[0]; //smaller
    int g = nums[nums.size() - 1]; //greater
    int q, r = 0; //qoutient reminder
    do
    {
        q = g / s;
        r = g % s;
        g = s;
        s = r>0?r:s;
    } while (r != 0);
    return s;
}
};
//100 PERCENT FASTER METHOD
class Solution {
public:
    int findGCD(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int den = nums[0]; 
        int num = nums[nums.size() - 1]; 
        if ((num % den) == 0)
            return den;
        int rem;
        while ((rem = (num % den)) != 0)
        {
            num = den;
            den = rem > 0?rem:den;
        }
        return den;
    }
};

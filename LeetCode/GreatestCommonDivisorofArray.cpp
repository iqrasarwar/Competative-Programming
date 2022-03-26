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

class Solution {
public:
    bool jump(vector<int>& v, int i, int s)
    {
        while(i>0)
        {
            if (v[i] + i >= s)
            {
                s = i;
                i--;
            }
            else
            i--;
        }
        if (i == 0 && v[i] + i >= s)
            return true;
        return false;
    }
bool canJump(vector<int>& nums) {
    if(nums.size() == 1)
    return true;
    return jump(nums, nums.size() - 2, nums.size() - 1);
}
};

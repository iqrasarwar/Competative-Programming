 //O(nlgn) time complexity
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> v,a,b;
        int half = nums.size() / 2;
        int size = nums.size();
        int odd = 0;
        if (size % 2 != 0)
        {
            odd = nums[size - 1];
            nums.pop_back();
            size--;
            for (int i = 0; i < size; i++)
            {
                if (odd + nums[i] == target)
                {
                    v.push_back(size);
                    v.push_back(i);
                    return v;
                }
            }
        }
        for (int i = 0; i < half; i++)
        {
            a.push_back(nums[i]);
        }
        for (int i = half; i < size; i++)
        {
            b.push_back(nums[i]);
        }
        for (int i = 0; i < size; i++)
        {

            for (int j = 0; j < half; j++)
            {
                if (nums[i] + a[j] == target && i!=j)
                {
                    v.push_back(i);
                    v.push_back(j);
                    return v;
                }
                if (nums[i] + b[j] == target && i!=j+half)
                {
                    v.push_back(i);
                    v.push_back(j+half);
                    return v;
                }
            }
        }
        return v;
    }
};

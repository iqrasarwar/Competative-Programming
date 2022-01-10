//still not excepted
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int store = -100000;
        if(nums.size()%2 == 0)
        {
            store = nums.back();
            nums.pop_back();
            if(store == target)
                return nums.size();
        }
        if(nums.size() == 1)
        {
            store = nums.back();
            nums.pop_back();
            if(store == target)
                return 0;
            else
                return -1;
        }
        int x =  recur(nums, 0, nums.size(), target);
        return x;
    }
    int recur(vector<int>& nums, int i, int j, int target)
    {
        if (i == j)
        {
            if (nums[i] == target)
                return i;
        }
        if (i > j)
            return -1;
        
        int mid = (i+j) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[i] <= nums[mid]) 
        {

            if (target >= nums[i] && target <= nums[mid])
                return recur(nums, i, mid - 1, target);
            return recur(nums, mid + 1, j, target);
        }
        if (target >= nums[mid] && target <= nums[j])
            return recur(nums, mid + 1, j, target);
        return recur(nums, i, mid - 1, target);
    }
    
};

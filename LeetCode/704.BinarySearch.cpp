class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = int(nums.size()) - 1;
        while(s<e)
        {
            int mid = s + (e-s+1)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                s = mid;
            else
                e = mid - 1;
        }
        return nums[s]==target?s:-1;
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    //     if (nums.size() == 2)
    // {
    //     if(nums[1]>nums[0])
    //         swap(nums[0],nums[1]);
    //         return;
    // }
        int size = nums.size();
    int index = 1;
    bool swapped = false;
    while (!swapped)
    {
        index++;
        int n = size - 1;
        int least = INT_MAX;
        int ind = n;
        for (int i = 0; i < index; i++)
        {
            if (n == 0)
            {
                sort(nums.begin(), nums.end());
                swapped = true;
                break;
            }
            if ((size - (index + 1)  > -1) && n > -1 && nums[n] > nums[size - (index + 1)] && nums[n] < least)
            {
                least = nums[n];
                ind = n;
            }
            if (nums[n] > nums[n - 1])
            {
                swap(nums[n - 1], nums[ind]);
                sort(nums.begin() + n, nums.end());
                swapped = true;
                break;
            }
            n--;
        }
    }
    }
};

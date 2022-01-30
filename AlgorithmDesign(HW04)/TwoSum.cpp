
//O(nlgn) time complexity algo hw 
//2t(n/2)+2n
void Sum(vector<int>& nums, int i, int j, int target,vector<int>& org)
{
    if (j - i - 1 > 2)
    {
        Sum(nums, i, i + j / 2, target,org);//t(n2)
        Sum(nums, i + j / 2, j, target,org);//t(n/2)
    }
    for (int k = 0; k < org.size(); k++)//n
    {
        if (org[k] + nums[i] == target)
        {
            cout << nums[i] << endl;
            cout << org[k] << endl;
        }
    }
    for (int k = 0; k < org.size(); k++)//n
    {
        if (org[k] + nums[i+1] == target)
        {
            cout << nums[i+1] << endl;
            cout << org[k] << endl;
        }
    }
}
//O(nsq) leetcode working
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

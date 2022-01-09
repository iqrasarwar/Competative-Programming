//nlgn complexity 2t(n/2)+2n

if (j - i - 1 > 2)
    {
        Sum(nums, i, i + j / 2,org);
        Sum(nums, i + j / 2, j,org);
    }
    for (int k = 0; k < org.size(); k++)
    {
        if (org[k] == nums[i])
        {
            cout << "same" << org[k] <<" "<< nums[i] << endl;
        }
    }
    for (int k = 0; k < org.size(); k++)
    {
        if (org[k] == nums[i+1])
        {
            cout << "same" << org[k] << " " << nums[i+1] << endl;
        }
    }

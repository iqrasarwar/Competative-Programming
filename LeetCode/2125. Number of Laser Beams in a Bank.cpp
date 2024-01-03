class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> v;
        for(int i =0;i < bank.size();i++) {
            int s =0;
            for(int j =0;j<bank[i].length();j++) 
                if(bank[i][j]=='1')  s++;
            if(s!=0)v.push_back(s);
        }
        if(v.size() ==0) return 0;
        int sum =0;
        for(int i=0;i<v.size()-1;i++)
        {
            sum+=(v[i]*v[i+1]);
        }
        return sum;
    }
};

https://leetcode.com/problems/number-of-laser-beams-in-a-bank/description/

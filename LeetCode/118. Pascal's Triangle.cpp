class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;
        vector<int> vv;
        vv.push_back(1);
        v.push_back(vv);
        int j = 1;
        while(numRows-- > 1)
        {
            vv.clear();
            vv.push_back(1);
            vector<int> vs = v.back();
            for(int i =0; i< j;i++)
            {
                if(i+1<j)
                    vv.push_back(vs[i]+vs[i+1]);
                else
                    break;
            }
            vv.push_back(1);
            v.push_back(vv);
            j++;
        }
        return v;
    }
};

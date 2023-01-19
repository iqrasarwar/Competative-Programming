/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode*> s;
        vector<vector<int>> v;
        if(!root)
        return v;
        s.push(root);
        while(!s.empty())
        {
            int si = s.size();
            vector<int> vv;
            for(int i=0;i<si;i++)
            {
                TreeNode* t = s.front();
                s.pop();
                if(t && t->left)
                s.push(t->left);
                if(t && t->right)
                s.push(t->right);
                vv.push_back(t->val);
            }
            v.push_back(vv);
        }
        return v;
    }
};

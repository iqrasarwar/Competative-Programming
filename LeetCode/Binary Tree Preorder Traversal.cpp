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
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        pt(root,ans);
        return ans;
    }
    void pt(TreeNode* root, vector<int> &ans) {
        if(!root) return;
        ans.push_back(root->val);
        pt(root->left, ans);
        pt(root->right, ans);
    }
};
//https://leetcode.com/submissions/detail/1136390701/

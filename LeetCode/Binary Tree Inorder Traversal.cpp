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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        it(root,ans);
        return ans;
    }
    void it(TreeNode* root, vector<int> &ans) {
        if(!root) return;
        it(root->left, ans);
        ans.push_back(root->val);
        it(root->right, ans);
    }
};
//https://leetcode.com/submissions/detail/1136395542/

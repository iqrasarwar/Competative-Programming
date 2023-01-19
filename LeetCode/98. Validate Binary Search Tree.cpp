class Solution {
public:
    TreeNode* prev=nullptr;
    bool isValidBST(TreeNode* root) {
         if(root!=nullptr){
            if(!isValidBST(root->left)) return false;

            if(prev!=nullptr && root->val<=prev->val) return false;

            prev=root;
            return isValidBST(root->right);
        }
        return true;
    }
};

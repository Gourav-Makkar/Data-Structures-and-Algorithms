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
    
    int height(TreeNode* root)
    {
        if(root==NULL)
            return -1;
        int lh=height(root->left);
        int rh=height(root->right);
        
        return max(lh,rh)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
            return true;
        int lh=height(root->left);
        int rh=height(root->right);
        
        if(abs(lh-rh)>1)
           return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};
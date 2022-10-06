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
    
    bool helper(TreeNode* lft,TreeNode* rght)
    {
        if(lft==NULL && rght==NULL)
            return true;
        if(lft==NULL || rght==NULL)
            return false;
        if(lft->val!=rght->val)
            return false;
        return (helper(lft->left,rght->right) && helper(lft->right,rght->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return helper(root->left,root->right);
    }
};
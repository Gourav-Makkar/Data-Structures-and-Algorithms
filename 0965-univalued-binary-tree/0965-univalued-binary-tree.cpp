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
    bool helper(TreeNode* root,int val)
    {
        if(root==NULL)
            return true;
        if(root->val!=val)
            return false;
        bool lft=helper(root->left,val);
        bool rght=helper(root->right,val);
        
        return (lft && rght);
    }
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL)
            return true;
        int val=root->val;
        return helper(root,val);
    }
};
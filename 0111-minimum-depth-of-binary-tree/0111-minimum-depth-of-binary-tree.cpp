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
    int helper(TreeNode* root)
    {
        if(root==NULL)
            return 1e9;
        if(root->left==NULL && root->right==NULL)
            return 1;
        
        int lft=1+helper(root->left);
        int rght=1+helper(root->right);
        
        return min(lft,rght);
    }
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
       return helper(root);
    }
};
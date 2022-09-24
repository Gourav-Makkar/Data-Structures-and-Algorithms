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
    
    bool helper(TreeNode*root,int targetSum,int cs)
    {
        if(root==NULL)
            return false;
        cs+=root->val;
        if(root->left==NULL && root->right==NULL && cs==targetSum)
            return true;
        return (helper(root->left,targetSum,cs) || helper(root->right,targetSum,cs));
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
       return helper(root,targetSum,0);
    }
};
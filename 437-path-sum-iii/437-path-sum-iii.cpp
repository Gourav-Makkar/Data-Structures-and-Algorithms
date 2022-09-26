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
    int ct=0;
    
    void helper(TreeNode* root,int target,long long cs)
    {
        if(root==NULL)
            return;
        cs+=root->val;
        if(cs==target)
        {
            ct++;
        }
        helper(root->left,target,cs);
        helper(root->right,target,cs);
        cs-=root->val;
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return 0;
        helper(root,targetSum,0);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        
        return ct;
    }
};
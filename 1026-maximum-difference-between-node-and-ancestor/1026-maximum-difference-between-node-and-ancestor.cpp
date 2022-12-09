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
    void find(TreeNode* root,int v,int &ans)
    {
        if(root==NULL)
            return;
        
        ans=max(ans,abs((root->val)-v));
        find(root->left,v,ans);
        find(root->right,v,ans); 
    }
    
    void helper(TreeNode* root,int &ans)
    {
        if(root==NULL)
            return;
        
        find(root->left,root->val,ans);
        find(root->right,root->val,ans);
        
        helper(root->left,ans);
        helper(root->right,ans);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ans=INT_MIN;
        
        helper(root,ans);
        return ans;
    }
};
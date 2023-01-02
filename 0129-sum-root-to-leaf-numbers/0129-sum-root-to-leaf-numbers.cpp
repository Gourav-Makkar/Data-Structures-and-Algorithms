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
    
    void helper(TreeNode* root,int curr,int &ans)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            curr=curr*10+root->val;
            ans+=curr;
            return;
        }
        curr=curr*10+root->val;
        helper(root->left,curr,ans);
        helper(root->right,curr,ans);
        
        curr=curr/10;
    }
    
    int sumNumbers(TreeNode* root) {
        int ans=0,curr=0;
        
        helper(root,curr,ans);
        return ans;
    }
};
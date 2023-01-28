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
    
    void helper(TreeNode* root,int k,int &ct,int &ans)
    {
        if(root==NULL)
            return;
        
        helper(root->left,k,ct,ans);
        ct++;
        if(ct==k)
        {
            ans=root->val;
            return;
        }
        helper(root->right,k,ct,ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ct=0;
        int ans;
        
        helper(root,k,ct,ans);
        return ans;
    }
};
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
    
    int helper(TreeNode* root,int &ans)
    {
        if(root==NULL)
            return 1;   
        
        int lft=helper(root->left,ans);
        int rght=helper(root->right,ans);
        
        if(lft==0 || rght==0)
        {
            ans++;                
            return 2;
        }
        else if(lft==2 || rght==2)
            return 1;               
        
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
        int ans=0;
        
        int ct=helper(root,ans);
        
        if(ct==0)
            ans++;
        return ans;
    }
};
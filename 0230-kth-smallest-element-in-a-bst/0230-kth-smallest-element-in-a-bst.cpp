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
    
    void inorder(TreeNode* root,int &ct,int &ans,int k)
    {
        if(root==NULL)
            return;
        inorder(root->left,ct,ans,k);
        ct++;
        if(ct==k)
        {
            ans=root->val;
            return;
        }
        inorder(root->right,ct,ans,k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
       int ans,ct=0;
       inorder(root,ct,ans,k);
       return ans;
    }
};
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
    
    int count(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int ct=1;
        ct+=count(root->left)+count(root->right);
        return ct;
    }
    
    int helper(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int sum=root->val;
        
        sum+=helper(root->left)+helper(root->right);
        return sum;
    }
    
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int sum=helper(root);
        int ct=count(root);
        int ans=0;
        if(sum/ct == root->val)
            ans++;
        ans+=averageOfSubtree(root->left)+averageOfSubtree(root->right);
        return ans;
    }
};
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
    
    int helper(TreeNode* root,unordered_map<TreeNode*,int>&m)
    {
        if(root==NULL)
            return 0;
        
        if(m.find(root)!=m.end())
            return m[root];
        
        int take=root->val;
        if(root->left)
            take+=helper(root->left->left,m)+helper(root->left->right,m);
        
        if(root->right)
            take+=helper(root->right->left,m)+helper(root->right->right,m);
        
        int notTake=helper(root->left,m)+helper(root->right,m);
        
        int ans=max(take,notTake);
        m[root]=ans;
        return ans;
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>m;
        
        return helper(root,m);
    }
};
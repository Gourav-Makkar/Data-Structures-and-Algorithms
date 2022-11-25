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
            return 0;
        int ans=0;
        if((root->val)%2==0)
        {
            if(root->left)
            {
                if(root->left->left)
                    ans+=root->left->left->val;
                if(root->left->right)
                    ans+=root->left->right->val;
            }
            if(root->right)
            {
                if(root->right->left)
                    ans+=root->right->left->val;
                if(root->right->right)
                    ans+=root->right->right->val;
            }
        }
        ans+= helper(root->left)+helper(root->right);
        
        return ans;
    }
    
    
    int sumEvenGrandparent(TreeNode* root) {
        return helper(root);
    }
};
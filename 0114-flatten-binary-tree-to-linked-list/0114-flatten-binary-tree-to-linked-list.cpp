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
    
    TreeNode* helper(TreeNode* root)
    {
       if(root==NULL)
           return NULL;
       
        TreeNode* temp=root->right;
        root->right=helper(root->left);
        root->left=NULL;
        
        TreeNode* curr=root;
        while(curr->right!=NULL)
            curr=curr->right;
        
        curr->right=helper(temp);
        return root;
    }
    
    void flatten(TreeNode* root) {
        helper(root);
    }
};
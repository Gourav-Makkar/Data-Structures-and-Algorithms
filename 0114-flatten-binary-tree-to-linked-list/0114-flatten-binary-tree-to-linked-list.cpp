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
        TreeNode* node=root;
        
        while(node->right!=NULL)
            node=node->right;
        
        node->right=helper(temp);
        
        return root;
    }
    
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        helper(root);
    }
};
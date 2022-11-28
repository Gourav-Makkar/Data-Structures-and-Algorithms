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
    int ans=0;
    int height(TreeNode* root)
    {
        if(root==NULL)
            return -1;
        int lh=height(root->left);
        int rh=height(root->right);
        
        return max(lh,rh)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        
        return max(lh+rh+2,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
        
        
    }
};
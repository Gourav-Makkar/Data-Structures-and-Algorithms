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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        if(root->val==key)
        {
            if(root->right==NULL)
                return root->left;
            TreeNode* curr=root->right;
            while(curr->left!=NULL)
                curr=curr->left;
            
            curr->left=root->left;
            return root->right;   
        }
        else if(root->val<key)
          root->right=deleteNode(root->right,key);
        else
          root->left=deleteNode(root->left,key);
        
        return root;
    }
};
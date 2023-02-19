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
    TreeNode* temp1=NULL,*temp2=NULL,*prev=NULL;
    
    void helper(TreeNode* root)
    {
        if(root==NULL)
            return;
        helper(root->left);
        
        if(prev!=NULL && root->val<prev->val)
        {
            if(temp1==NULL)
                temp1=prev;
            temp2=root;
        }
        prev=root;
        helper(root->right);
    }
    
    void recoverTree(TreeNode* root) {
       helper(root);
       swap(temp1->val,temp2->val);
    }
};
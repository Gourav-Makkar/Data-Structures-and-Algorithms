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
    
    void dfs(TreeNode* root,TreeNode* &temp1,TreeNode* &temp2,TreeNode* &prev)
    {
        if(root==NULL)
            return;
        dfs(root->left,temp1,temp2,prev);
        
        if(prev!=NULL && prev->val>root->val)
        {
            if(!temp1)
                temp1=prev;
            temp2=root;
        }
        prev=root;
        
        dfs(root->right,temp1,temp2,prev);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode* temp1=NULL,*temp2=NULL,*prev=NULL;
        dfs(root,temp1,temp2,prev);
        
        swap(temp1->val,temp2->val);
    }
};
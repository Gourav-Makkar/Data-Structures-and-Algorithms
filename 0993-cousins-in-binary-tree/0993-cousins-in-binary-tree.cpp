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
    int xlvl=-1,ylvl=-1;
    TreeNode* parx=NULL,*pary=NULL;
    
    void dfs(TreeNode* root,int x,int y,int lvl,TreeNode* par)
    {
        if(root==NULL)
            return;
        
        if(root->val==x)
        {
            xlvl=lvl;
            parx=par;
            return;
        }
        if(root->val==y)
        {
            ylvl=lvl;
            pary=par;
            return;
        }
        dfs(root->left,x,y,lvl+1,root);
        dfs(root->right,x,y,lvl+1,root);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
       
        dfs(root,x,y,0,NULL);
        if(xlvl==ylvl && parx!=pary)
            return true;
        return false;
    }
};
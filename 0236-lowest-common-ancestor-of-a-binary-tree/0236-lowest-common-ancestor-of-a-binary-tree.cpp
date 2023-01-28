/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void helper(TreeNode* root,TreeNode* p,vector<TreeNode*>&path)
    {
        if(root==NULL)
            return;
        if(root==p)
        {
            path.push_back(root);
            return;
        }
        path.push_back(root);
        
        helper(root->left,p,path);
        helper(root->right,p,path);
        
        if(path.back()!=p)
            path.pop_back();
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1,path2;
        
        helper(root,p,path1);
        helper(root,q,path2);
        
        int i=0,j=0,n1=path1.size(),n2=path2.size();
        TreeNode* ans;
        
        while(i<n1 && j<n2)
        {
            if(path1[i]==path2[j])
            {
                ans=path1[i];
            }
            i++;
            j++;
        }
        return ans;
    }
};
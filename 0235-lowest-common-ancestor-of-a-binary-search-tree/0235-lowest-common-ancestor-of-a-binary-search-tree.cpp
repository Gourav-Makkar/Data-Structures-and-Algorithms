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
    
    void helper(TreeNode* root,TreeNode* des,vector<int>&path)
    {
        if(root==NULL)
            return;
        if(root==des)
        {
            path.push_back(root->val);
            return;
        }
        path.push_back(root->val);
        
        helper(root->left,des,path);
        helper(root->right,des,path);
        
        if(path.back()!=des->val)
            path.pop_back();
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int>p1,p2;
        
        helper(root,p,p1);
        helper(root,q,p2);
        
        int i=0,j=0;
        TreeNode* ans;
        
        while(i<p1.size() && j<p2.size())
        {
            if(p1[i]==p2[j])
              ans=new TreeNode(p1[i]);
            i++;
            j++;
        }
        
        return ans;
        
    }
};
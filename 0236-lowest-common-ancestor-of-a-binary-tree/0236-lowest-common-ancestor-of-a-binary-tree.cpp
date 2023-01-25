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
    
    void helper(TreeNode* root,TreeNode* des,vector<TreeNode*>&path)
    {
        if(root==NULL)
            return;
        if(root==des)
        {
            path.push_back(root);
            return;
        }
        path.push_back(root);
        helper(root->left,des,path);
        helper(root->right,des,path);
        if(path.back()==root)
            path.pop_back();
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        
        vector<TreeNode*>path1,path2;
        
        for(auto it:path1)
            cout<<it->val<<" ";
        cout<<endl;
        for(auto it:path2)
            cout<<it->val<<" ";
        
        helper(root,p,path1);
        helper(root,q,path2);
        
        int i=0,j=0;
        TreeNode* ans;
        
        while(i<path1.size() && j<path2.size())
        {
            if(path1[i]==path2[j])
                ans=path1[i];
            i++;
            j++;
        }
        return ans;
    }
};
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
    
    // int find(int val,vector<int>&inorder)
    // {
    //     int n=inorder.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         if(inorder[i]==val)
    //             return i;
    //     }
    //     return -1;
    // }
    
    TreeNode* make(int &idx,vector<int>&postorder,int st,int en,unordered_map<int,int>&m)
    {
        if(st>en)
            return NULL;
        
        int val=postorder[idx--];
        int pos=m[val];
        TreeNode* root=new TreeNode(val);
        
        root->right=make(idx,postorder,pos+1,en,m);
        root->left=make(idx,postorder,st,pos-1,m);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size(),idx=n-1;
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++)
            m[inorder[i]]=i;
        
        return make(idx,postorder,0,n-1,m);
    }
};
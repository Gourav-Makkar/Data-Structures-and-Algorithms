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
    int idx=0;
    
    TreeNode* build(vector<int>& preorder,map<int,int>&m,int st,int en)
    {
        if(st>en)
            return NULL;
        int val=preorder[idx++];
        int idx=m[val];
        TreeNode* temp=new TreeNode(val);
        
        temp->left=build(preorder,m,st,idx-1);
        temp->right=build(preorder,m,idx+1,en);
        
        return temp;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        map<int,int>m;
        
        for(int i=0;i<n;i++)
            m[inorder[i]]=i;
        
        return build(preorder,m,0,n-1);
    }
};
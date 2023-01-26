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
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int st,int en)
    {
        if(st>en)
            return NULL;
        int val=preorder[idx++];
        int idx=-1;
        for(int i=st;i<=en;i++)
        {
            if(inorder[i]==val)
            {
                idx=i;
                break;
            }
        }
        TreeNode* temp=new TreeNode(val);
        
        temp->left=build(preorder,inorder,st,idx-1);
        temp->right=build(preorder,inorder,idx+1,en);
        
        return temp;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return build(preorder,inorder,0,n-1);
    }
};
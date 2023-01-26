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
    int idx;
    
    TreeNode* build(vector<int>& postorder, vector<int>& inorder,int st,int en)
    {
        if(st>en)
            return NULL;
        int val=postorder[idx--];
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
        
        temp->right=build(postorder,inorder,idx+1,en);
        temp->left=build(postorder,inorder,st,idx-1);
        
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size();
        idx=n-1;
        return build(postorder,inorder,0,n-1);
    }
};
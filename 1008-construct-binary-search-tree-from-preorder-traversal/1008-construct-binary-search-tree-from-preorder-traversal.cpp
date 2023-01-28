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
    int mx=INT_MAX,idx=0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(idx==preorder.size() || preorder[idx]>=mx)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[idx++]);
        int prev=mx;
        mx=root->val;
        root->left=bstFromPreorder(preorder);
        
        mx=prev;
        root->right=bstFromPreorder(preorder);
        
        return root;
        
        
        
    }
};
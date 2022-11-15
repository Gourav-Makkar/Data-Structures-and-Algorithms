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
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        TreeNode* lft=root,*rght=root;
        int l=0,r=0;
        while(lft!=NULL)
        {
            l++;
            lft=lft->left;
        }
        while(rght!=NULL)
        {
            r++;
            rght=rght->right;
        }
        if(l==r)
            return pow(2,l) - 1;
        return 1 + countNodes(root->left)+ countNodes(root->right);
    }
};
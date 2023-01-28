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
    
    
    bool check(TreeNode* root,long long mn,long long mx)
    {
        if(root==NULL)
            return true;
        
        if((long long)root->val<=mn || (long long)root->val>=mx)
            return false;
        
        return check(root->left,mn,(long long)root->val) && check(root->right,(long long)root->val,mx);
    }
    
    bool isValidBST(TreeNode* root) {
        long long mn=LLONG_MIN,mx=LLONG_MAX;
        
        return check(root,mn,mx);
    }
};
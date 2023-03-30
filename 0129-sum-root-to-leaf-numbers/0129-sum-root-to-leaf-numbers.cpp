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
    
    void helper(TreeNode* root,string curr,int &ans)
    {
        if(root==NULL)
            return;
        
        if(!root->left && !root->right)
        {
            curr+=to_string(root->val);
            int temp=stoi(curr);
            ans+=temp;
            return;
        }
        curr+=to_string(root->val);
        helper(root->left,curr,ans);
        helper(root->right,curr,ans);
    }
    
    int sumNumbers(TreeNode* root) {
        int ans=0;
        helper(root,"",ans);
        return ans;
    }
};
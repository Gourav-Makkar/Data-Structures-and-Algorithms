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
    
    void helper(TreeNode* root,string curr,string &ans)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            curr+=(root->val)+97;
            
            reverse(curr.begin(),curr.end());
            
            if(ans.size()==0)
                ans=curr;
            else
            {
                ans=min(ans,curr);
            }
            return;
        }
        
        curr+=(root->val)+97;
        
        helper(root->left,curr,ans);
        helper(root->right,curr,ans);
        
        curr.pop_back();
    }
    
    string smallestFromLeaf(TreeNode* root) {
        string curr="";
        string ans="";
        
        helper(root,curr,ans);
        return ans;
    }
};
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
    unordered_map<string,int>m;
    string helper(TreeNode* root,vector<TreeNode*>&ans)
    {
        if(root==NULL)
            return "@";
        
        string temp= to_string(root->val) + "-" + helper(root->left,ans) + "-" + helper(root->right,ans);
        
        if(m[temp]==1)
            ans.push_back(root);
        m[temp]++;
           
        // cout<<temp<<endl;
        
        return temp;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        
        if(!root)
            return ans;
        helper(root,ans);
        return ans;
    }
};
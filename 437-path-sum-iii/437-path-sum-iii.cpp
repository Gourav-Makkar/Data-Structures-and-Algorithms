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
    int ct=0;
    unordered_map<long long,int>m;
    
    void helper(TreeNode* root,int target,long long cs)
    {
        if(root==NULL)
            return;
        cs+=root->val;
        if(cs==target)
        {
            ct++;
        }
        if(m.find(cs-target)!=m.end())
        {
            ct+=m[cs-target];
        }
        m[cs]++;
        helper(root->left,target,cs);
        helper(root->right,target,cs);
        m[cs]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
            return 0;
        helper(root,targetSum,0);
        
        return ct;
    }
};
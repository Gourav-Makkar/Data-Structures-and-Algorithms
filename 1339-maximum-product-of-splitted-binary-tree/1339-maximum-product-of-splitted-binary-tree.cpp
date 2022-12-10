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
#define ll long long
class Solution {
public:
    int mod=1e9+7;
    
    ll findSum(TreeNode* root,unordered_map<TreeNode*,ll>&m)
    {
        int sum=0;
        if(root==NULL)
            return sum;
        sum+=root->val;
        
        sum+=findSum(root->left,m);
        sum+=findSum(root->right,m);
        
        return m[root]=sum;
    }
    
    void helper(TreeNode* root,ll sum,ll &ans,unordered_map<TreeNode*,ll>&m)
    {
        if(root==NULL)
            return;
        if(root->left)
        {
            ll s1=m[root->left];
            ll s2=sum-s1;
            
            ans=max(ans,s1*s2);
        }
        if(root->right)
        {
            ll s1=m[root->right];
            ll s2=sum-s1;
            
            ans=max(ans,s1*s2);
        }
        
        helper(root->left,sum,ans,m);
        helper(root->right,sum,ans,m);
    }
    
    int maxProduct(TreeNode* root) {
        
        unordered_map<TreeNode*,ll>m;
        ll sum=findSum(root,m);
        ll ans=0;
        helper(root,sum,ans,m);
        
        return ans%mod;
    }
};
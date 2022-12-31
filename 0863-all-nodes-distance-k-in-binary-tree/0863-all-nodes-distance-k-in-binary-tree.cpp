/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void helper(TreeNode* root,vector<int>adj[])
    {
        if(root==NULL)
            return;
        if(root->left!=NULL)
        {
            adj[root->left->val].push_back(root->val);
            adj[root->val].push_back(root->left->val);
        }
        if(root->right!=NULL)
        {
            adj[root->right->val].push_back(root->val);
            adj[root->val].push_back(root->right->val);
        }
        
        helper(root->left,adj);
        helper(root->right,adj);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        int tar=target->val;
        
        vector<int>adj[501];
        vector<int>ans;
        vector<int>vis(501,0);
        
        if(k==0)
        {
            ans.push_back(tar);
            return ans;
        }
        
        helper(root,adj);
        
        queue<pair<int,int>>q;
        
        vis[tar]=1;
        
        for(auto it:adj[tar])
            q.push({it,1});
        
        
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            
            vis[p.first]=1;
            
            if(p.second==k)
                ans.push_back(p.first);
            
            else if(p.second<k)
            {
                for(auto it:adj[p.first])
                {
                    if(vis[it]==0)
                        q.push({it,p.second+1});
                }
            }
        }
        return ans;
    }
};
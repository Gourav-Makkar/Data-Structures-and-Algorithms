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
    unordered_map<int,vector<int>>m;
    
    void helper(TreeNode* root)
    {
        queue<pair<TreeNode*,int>>q;
        q.push({root,-1});
        
        while(!q.empty())
        {
            TreeNode* curr=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            if(parent!=-1)
            {
                m[parent].push_back(curr->val);
                m[curr->val].push_back(parent);
            }
            if(curr->left)
                q.push({curr->left,curr->val});
            if(curr->right)
                q.push({curr->right,curr->val});
        }
    }
    
    int amountOfTime(TreeNode* root, int start) {
        helper(root);
        int ans=INT_MIN;
        unordered_map<int,bool>vis;
        
        queue<pair<int,int>>q;
        q.push({start,0});
        
        while(!q.empty())
        {
            int curr=q.front().first;
            int dis=q.front().second;
            q.pop();
            ans=max(ans,dis);
            
            for(auto it:m[curr])
            {
                if(!vis[it])
                  {
                    q.push({it,dis+1});
                    vis[curr]=true;
                  }
            }
        }
        return ans;
    }
};
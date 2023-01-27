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
    
    void make_graph(TreeNode* root,int parent,map<int,vector<int>>&m)
    {
        if(parent!=-1)
        {
            m[root->val].push_back(parent);
            m[parent].push_back(root->val);
        }
        if(root->left)
            make_graph(root->left,root->val,m);
        if(root->right)
            make_graph(root->right,root->val,m);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<int,vector<int>>m;
        make_graph(root,-1,m);
        
        map<int,bool>vis;
        vector<int>ans;
        
        queue<pair<int,int>>q;
        q.push({target->val,0});
        vis[target->val]=1;
        
        while(!q.empty())
        {
            int curr=q.front().first;
            int dis=q.front().second;
            q.pop();
            
            if(dis>k)
                break;
            if(dis==k)
            {
                ans.push_back(curr);
                continue;
            }
            
            for(auto it:m[curr])
            {
                if(vis[it]==0)
                {
                    vis[it]=1;
                    q.push({it,dis+1});
                }
            }
        }
        return ans;
    }
};
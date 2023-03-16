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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>>m;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        
        while(!q.empty())
        {
            int n=q.size();
            map<int,vector<int>>temp;
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front().first;
                int lvl=q.front().second;
                q.pop();
                
                temp[lvl].push_back(curr->val);
                
                if(curr->left)
                    q.push({curr->left,lvl-1});
                if(curr->right)
                    q.push({curr->right,lvl+1});
            }
            for(auto it:temp)
            {
                vector<int>v;
                for(auto it1:it.second)
                    v.push_back(it1);
                sort(v.begin(),v.end());
                
                for(auto it1:v)
                    m[it.first].push_back(it1);
            }
        }
        vector<vector<int>>ans;
        
        for(auto it:m)
        {
            vector<int>curr;
            for(auto it1:it.second)
                curr.push_back(it1);
            ans.push_back(curr);
        }
        return ans;
    }
};
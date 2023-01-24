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
        m[0].push_back(root->val);
        
        while(!q.empty())
        {
            queue<pair<TreeNode*,int>>tq;
            
            while(!q.empty())
            {
                TreeNode* temp=q.front().first;
                int lvl=q.front().second;
                q.pop();
                
                if(temp->left)
                    tq.push({temp->left,lvl-1});
                if(temp->right)
                    tq.push({temp->right,lvl+1});
            }
            q=tq;
            vector<pair<int,int>>v;
            while(tq.size())
            {
                v.push_back({tq.front().second,tq.front().first->val});
                tq.pop();
            }
            sort(v.begin(),v.end());
            for(auto it:v)
                m[it.first].push_back(it.second);
        }
        vector<vector<int>>ans;
        
        for(auto it:m)
        {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
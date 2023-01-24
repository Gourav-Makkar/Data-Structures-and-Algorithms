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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        
        if(root==NULL)
            return ans;
        
        bool flag=false;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>curr;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                curr.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(flag)
                reverse(curr.begin(),curr.end());
            ans.push_back(curr);
            flag=!flag;
        }
        return ans;
    }
};
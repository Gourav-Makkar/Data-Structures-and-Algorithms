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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,1});
        long long ans=0;
        
        while(!q.empty())
        {
            int n=q.size();
            long long lc=0,rc=0,mn=q.front().second;
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front().first;
                long long pos=(q.front().second) - mn;
                q.pop();
                
                if(i==0)
                    lc=pos;
                if(i==n-1)
                    rc=pos;
                
                if(curr->left)
                    q.push({curr->left,2*pos});
                if(curr->right)
                    q.push({curr->right,2*pos+1});
            }
             ans=max(ans,rc-lc+1);
        }
        return ans;
    }
};
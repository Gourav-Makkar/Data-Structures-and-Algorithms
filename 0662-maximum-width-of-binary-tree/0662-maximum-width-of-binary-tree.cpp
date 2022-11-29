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
            long long l=0,r=0;
            long long mn=q.front().second;
            for(int i=0;i<n;i++)
            {
                long long idx=q.front().second - mn;
                TreeNode* temp=q.front().first;
                q.pop();
                if(i==0)
                    l=idx;
                if(i==n-1)
                    r=idx;
                if(temp->left)
                {
                    q.push({temp->left,2*idx});
                }
                if(temp->right)
                {
                    q.push({temp->right,2*idx+1});
                }
            }
            ans=max(ans,r-l+1);
        }
        return ans;
        
    }
};
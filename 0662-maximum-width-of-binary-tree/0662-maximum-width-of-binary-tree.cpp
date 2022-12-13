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
        long long ans=1;
        
        while(!q.empty())
        {
            int n=q.size();
            long long l,r;
            long long mn=q.front().second;
            
            for(int i=0;i<n;i++)
            {
                auto p=q.front();
                TreeNode* temp=p.first;
                long long val=p.second;
                
                q.pop();
                
                if(i==0)
                    l=val;
                if(i==n-1)
                    r=val;
                
                if(temp->left)
                    q.push({temp->left,2*val - mn});
                if(temp->right)
                    q.push({temp->right,2*val+1 - mn});
            }
            ans=max(ans,r-l+1);
        }
        
        return ans;
    }
};
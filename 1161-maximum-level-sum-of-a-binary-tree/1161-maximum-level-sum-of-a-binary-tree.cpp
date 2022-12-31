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
    int maxLevelSum(TreeNode* root) {
        int ans;
        long long mx=INT_MIN;
        
        queue<TreeNode*>q;
        q.push(root);
        int l=0;
        
        while(!q.empty())
        {
            int n=q.size();
            l++;
            long long sum=0;
            
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                
                sum+=temp->val;
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            if(sum>mx)
            {
                mx=sum;
                ans=l;
            }
        }
        
        return ans;
        
    }
};
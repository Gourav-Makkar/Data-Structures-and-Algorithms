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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>ans;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int n=q.size();
            long long cs=0;
            
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                
                cs+=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            ans.push_back(cs);
        }
        sort(ans.begin(),ans.end(),greater<long long>());
        if(ans.size()<k)
            return -1;
        return ans[k-1];
    }
};
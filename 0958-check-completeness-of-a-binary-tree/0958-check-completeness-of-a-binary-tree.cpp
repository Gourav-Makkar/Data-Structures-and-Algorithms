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
    bool isCompleteTree(TreeNode* root) {
        
        int tl=-1;
        TreeNode* temp=root;
        while(temp)
        {
            tl++;
            temp=temp->left;
        }
        
        int cl=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        
        int prev=-1;
        
        while(!q.empty())
        {
            int n=q.size();
            if(cl!=tl && pow(2,cl)!=n)
              return false;
                
            for(int i=0;i<n;i++)
            {
                TreeNode* curr=q.front().first;
                int node=q.front().second;
                q.pop();
                if(prev!=-1)
                {
                    if(prev+1!=node)
                        return false;
                }
                prev=node;
                
                if(curr->left)
                    q.push({curr->left,2*node});
                if(curr->right)
                    q.push({curr->right,2*node+1});
            }
            cl++;
        }
        return true;
    }
};
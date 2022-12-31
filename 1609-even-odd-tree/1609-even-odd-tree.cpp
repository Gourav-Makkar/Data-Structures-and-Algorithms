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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
        while(!q.empty())
        {
            int n=q.size();
            if(flag)
            {
                int mx=INT_MIN;
                for(int i=0;i<n;i++)
                {
                    TreeNode* temp=q.front();
                     q.pop();
                    int data=temp->val;
                    
                    if(data%2==0 || data<=mx)
                        return false;
                    else
                        mx=data;
                    
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                }
                
            }
            else
            {
                int mx=INT_MAX;
                for(int i=0;i<n;i++)
                {
                    TreeNode* temp=q.front();
                     q.pop();
                    int data=temp->val;
                    
                    if(data%2!=0 || data>=mx)
                        return false;
                    else
                        mx=data;
                    
                    if(temp->left)
                        q.push(temp->left);
                    if(temp->right)
                        q.push(temp->right);
                }
            }
            flag=!flag;
        }
        return true;
    }
};
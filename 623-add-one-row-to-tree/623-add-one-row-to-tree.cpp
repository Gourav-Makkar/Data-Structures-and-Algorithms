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
    
    void helper(TreeNode* root,int val,int depth,int cd)
    {
        if(root==NULL)
            return;
        if(cd==depth-1)
        {
             TreeNode* lft=new TreeNode(val);
             TreeNode* rght=new TreeNode(val);
             
             lft->left=root->left;
             rght->right=root->right;
             
             root->left=lft;
             root->right=rght;
        }
        helper(root->left,val,depth,cd+1);
        helper(root->right,val,depth,cd+1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(root==NULL)
            return NULL;
        if(depth==1)
        {
            TreeNode* temp=new TreeNode(val);
            temp->left=root;
            return temp;
        }
        helper(root,val,depth,1);
        
        return root;
        
//         queue<TreeNode*>q;
//         q.push(root);
//         int cd=0;
//         while(!q.empty() && cd!=depth-1)
//         {
//             int ct=q.size();
//             cd++;
//             for(int i=0;i<ct;i++)
//             {
//                 TreeNode* temp=q.front();
//                 q.pop();
//                 if(cd==depth-1)
//                 {
//                     TreeNode* lft=new TreeNode(val);
//                     TreeNode* rght=new TreeNode(val);
                    
//                     lft->left=temp->left;
//                     rght->right=temp->right;
                    
//                     temp->left=lft;
//                     temp->right=rght;
//                 }
//                 if(temp->left)
//                     q.push(temp->left);
//                 if(temp->right)
//                     q.push(temp->right);  
//             }
//         }
//         return root;
    }
};
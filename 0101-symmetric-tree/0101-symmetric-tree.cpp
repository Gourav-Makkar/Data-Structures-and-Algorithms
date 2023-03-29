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
    
//     bool helper(TreeNode* r1,TreeNode* r2)
//     {
//         if(!r1 && !r2)
//             return true;
//         if(!r1 && r2 || r1 && !r2 || r1->val!=r2->val)
//             return false;
        
//         return helper(r1->left,r2->right) && helper(r1->right,r2->left);
//     }
    
    bool isSymmetric(TreeNode* root) {
       // return helper(root,root);
        
        queue<TreeNode*>q;
        if(root==NULL)
            return true;
        
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty()){
            TreeNode* l=q.front();
            q.pop();
            
            TreeNode* r=q.front();
            q.pop();
            
            
            
            if(!l && r || l &&!r ||(l!=NULL && r!=NULL && l->val!=r->val))
                return false;
            if(!l && !r)
               continue;
               
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }
        return true;
    }
};
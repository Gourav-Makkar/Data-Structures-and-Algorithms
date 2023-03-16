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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        stack<TreeNode*>st;
        
        while(!st.empty() || curr)
        {
            if(curr)
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                TreeNode* node=st.top()->right;
                if(node==NULL)
                {
                    node=st.top();
                    st.pop();
                    ans.push_back(node->val);
                    
                    while(!st.empty() && st.top()->right==node)
                    {
                        node=st.top();
                        st.pop();
                        ans.push_back(node->val);
                    }
                }
                else
                    curr=node;
            }
        }
        return ans;
    }
};
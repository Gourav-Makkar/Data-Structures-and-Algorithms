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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
            return ans;
        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* temp=st.top();
            st.pop();
            while(!st.empty() || temp!=NULL)
            {
                if(temp==NULL)
                {
                    temp=st.top();
                    st.pop();
                }
                if(temp->right)
                  st.push(temp->right);
                ans.push_back(temp->val);
                temp=temp->left;
            }
            if(!st.empty())
            {
                temp=st.top();
                st.pop();
            }
        }
        return ans;
    }
};
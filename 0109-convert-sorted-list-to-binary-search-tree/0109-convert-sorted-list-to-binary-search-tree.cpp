/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    TreeNode* createTree(int st,int en,vector<int>&temp)
    {
        if(st>en)
            return NULL;
        
        int mid=st+(en-st)/2;
        TreeNode* root=new TreeNode(temp[mid]);
        
        root->left=createTree(st,mid-1,temp);
        root->right=createTree(mid+1,en,temp);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>temp;
        ListNode* curr=head;
        while(curr)
        {
            temp.push_back(curr->val);
            curr=curr->next;
        }
        
        return createTree(0,temp.size()-1,temp);
    }
};
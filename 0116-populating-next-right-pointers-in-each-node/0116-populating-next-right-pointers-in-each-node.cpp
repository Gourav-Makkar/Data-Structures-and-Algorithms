/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
//     void dfs(Node* left,Node* right)
//     {
//         if(left==NULL)
//             return;
//         left->next=right;
        
//         dfs(left->left,left->right);
//         dfs(left->right,right->left);
//         dfs(right->left,right->right);
//     }
    
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        // dfs(root->left,root->right);
        // return root;
        
        Node* left=root;
        while(left->left)
        {
            Node* curr=left;
            while(curr)
            {
                curr->left->next=curr->right;
                if(curr->next)
                    curr->right->next=curr->next->left;
                
                curr=curr->next;
            }
            left=left->left;
        }
        return root;
    }
};
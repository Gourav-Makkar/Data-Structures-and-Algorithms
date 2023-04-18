/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr=head,*newHead=NULL;
        unordered_map<Node*,Node*>m;
        
        while(curr!=NULL)
        {
            //creating new curr node
            if(m.find(curr)==m.end())
            {
                Node* temp=new Node(curr->val);
            
                if(newHead==NULL)
                  newHead=temp;
                m[curr]=temp;
            }
            
            //handling next pointer
            Node* temp;
            if(curr->next!=NULL && m.find(curr->next)==m.end())
            {
                temp=new Node(curr->next->val);
                m[curr->next]=temp;
            }
            if(curr->next)
                m[curr]->next=m[curr->next];
            
            //handling random pointer
            if(curr->random!=NULL && m.find(curr->random)==m.end())
            {
                temp=new Node(curr->random->val);
                m[curr->random]=temp;
            }
            
            if(curr->random)
                m[curr]->random=m[curr->random];
            
            curr=curr->next;
        }
        return newHead;
    }
};
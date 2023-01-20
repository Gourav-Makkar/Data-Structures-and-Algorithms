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
       Node* curr=head;
        
       while(curr!=NULL)
       {
           int v=curr->val;
           Node* temp=new Node(v);
           temp->next=curr->next;
           curr->next=temp;
           curr=temp->next;
       }
        
       curr=head;
       while(curr!=NULL)
       {
           Node* temp=curr->next;
           if(curr->random!=NULL)
               temp->random=curr->random->next;
           curr=temp->next;
       }
       Node* h=NULL,*t=NULL;
       curr=head;
       while(curr!=NULL)
       {
           if(h==NULL)
           {
               h=curr->next;
               t=curr->next;
           }
           else
           {
               t->next=curr->next;
               t=t->next;
           }
               
           curr->next=curr->next->next;
           curr=curr->next;
       }
        return h;
    }
};
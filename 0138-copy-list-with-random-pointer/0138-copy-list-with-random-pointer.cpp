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
        Node* h=NULL,*t=NULL;
        unordered_map<Node*,int>m1;
        unordered_map<int,Node*>m2;
        
        int idx=0;
        Node* curr=head;
        while(curr!=NULL)
        {
            m1[curr]=idx;
            int v=curr->val;
            
            Node* temp=new Node(v);
            m2[idx]=temp;
            
            // if(h==NULL)
            // {
            //     h=temp;
            //     t=temp;
            // }
            
            idx++;
            curr=curr->next;
        }
        curr=head;
        
        while(curr!=NULL)
        {
            int idx=m1[curr];
            
            Node* temp=m2[idx];
            if(h==NULL)
            {
                h=temp;
                t=temp;
            }
            
            else
            {
                t->next=temp;
                t=t->next;
            }
            if(curr->random==NULL)
                temp->random=NULL;
            else
            {
                int ridx=m1[curr->random];
                temp->random=m2[ridx];
            }
            
            curr=curr->next;
        }
        return h;
    }
};
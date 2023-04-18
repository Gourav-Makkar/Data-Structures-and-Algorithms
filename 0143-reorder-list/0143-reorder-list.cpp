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
class Solution {
public:
    
    void merge(ListNode* slow,ListNode* fast)
    {
       while(fast!=NULL)
       {
           ListNode* temp=slow->next;
           slow->next=fast;
           fast=fast->next;
           slow->next->next=temp;
           slow=temp;
       }
    }
    
    ListNode* reverse(ListNode* curr)
    {
        ListNode* prev=NULL,*nxt=NULL;
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
       ListNode* slow=head,*fast=head;
       
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        fast=slow->next;
        slow->next=NULL;
        slow=head;
        
        fast=reverse(fast);
        
        merge(slow,fast);
    }
};
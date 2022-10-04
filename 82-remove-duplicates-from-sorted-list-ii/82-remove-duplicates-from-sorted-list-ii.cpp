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
    ListNode* deleteDuplicates(ListNode* head) {
       if(head==NULL || head->next==NULL)
           return head;
       ListNode* head1=NULL,*tail=NULL;
       ListNode* prev=NULL,*curr=head,*nxt=head->next;
       while(nxt!=NULL)
       {
          if((prev!=NULL && prev->val==curr->val) || (curr->val==nxt->val))
          {
              prev=curr;
              curr=nxt;
              nxt=nxt->next;
          }
           else
           {
               if(head1==NULL)
               {
                   head1=curr;
                   tail=curr;
               }
               else
               {
                   tail->next=curr;
                   tail=tail->next;
               }
              prev=curr;
              curr=nxt;
              nxt=nxt->next;
           }
       }
        if(curr->val!=prev->val)
        {
            if(head1==NULL)
               {
                   head1=curr;
                   tail=curr;
               }
               else
               {
                   tail->next=curr;
                   tail=tail->next;
               }
        }
        if(tail!=NULL)
         tail->next=NULL;
        return head1;
    }
};
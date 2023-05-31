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
    ListNode* reversell(ListNode* head,int k,int grps)
    {
        if(grps==0)
            return head;
        ListNode* curr=head,*prev=NULL,*nxt=NULL;
        int ct=0;
        while(curr!=NULL &&ct<k)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            ct++;
        }
        head->next=reversell(curr,k,grps-1);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        int grps=0;
        int ct=0;
        ListNode* cur=head;
       while(cur!=NULL)
       {
           ct++;
           cur=cur->next;
       }
        grps=ct/k;
        return reversell(head,k,grps);
    }
};
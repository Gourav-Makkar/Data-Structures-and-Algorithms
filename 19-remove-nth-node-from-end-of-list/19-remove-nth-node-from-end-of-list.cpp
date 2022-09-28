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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL && n==1)
            return NULL;
        int ct=0;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            curr=curr->next;
            ct++;
        }
        if(ct==n)
        {
            head=head->next;
            return head;
        }
        int p=ct-n-1;
        curr=head;
        while(p-- && curr!=NULL)
        {
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;
    }
};
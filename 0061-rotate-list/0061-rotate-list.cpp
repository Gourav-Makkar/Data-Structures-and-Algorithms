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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL)
            return head;
        int ct=0;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            ct++;
            curr=curr->next;
        }
        if(k>ct)
            k=k%ct;
        if(k==ct || k==0)
            return head;
        ct=ct-k-1;
        curr=head;
        while(curr!=NULL && ct>0)
        {
            curr=curr->next;
            ct--;
        }
        ListNode* temp=curr->next;
        curr->next=NULL;
        
        curr=temp;
        while(curr->next!=NULL)
            curr=curr->next;
        curr->next=head;
        head=temp;
        return head;
    }
};
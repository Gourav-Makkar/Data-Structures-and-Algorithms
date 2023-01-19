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
        ListNode* curr=head;
        int l=0;
        
        while(curr!=NULL)
        {
            l++;
            curr=curr->next;
        }
        
        if(n==l)
            return head->next;
        
        int ct=l-n-1;
        curr=head;
        
        while(ct--)
            curr=curr->next;
        curr->next=curr->next->next;
        return head;
    }
};
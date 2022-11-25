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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* slow=head,*fast=head;
        int ct=k;
        while(ct-- && fast!=NULL)
            fast=fast->next;
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        fast=head;
        k=k-1;
        while(k--)
            fast=fast->next;
        int temp=fast->val;
        fast->val=slow->val;
        slow->val=temp;
        
        return head;
    }
};
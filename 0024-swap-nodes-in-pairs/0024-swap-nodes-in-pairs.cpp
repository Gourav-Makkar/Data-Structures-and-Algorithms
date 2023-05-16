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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* nh=head->next;
        ListNode* t1=head,*t2=head->next;
        
        ListNode* nxt=t2->next;
        
        while(t2)
        {
            t2->next=t1;
            
            if(nxt==NULL || nxt->next==NULL)
            {
                t1->next=nxt;
                break;
            }
            t1->next=nxt->next;
            t2=t1->next;
            t1=nxt;
            nxt=t2->next;
        }
        return nh;
    }
};
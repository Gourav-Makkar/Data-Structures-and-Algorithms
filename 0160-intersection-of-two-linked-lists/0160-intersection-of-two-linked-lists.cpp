/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr=headA;
        int lenA=0,lenB=0;
        
        while(curr!=NULL)
        {
            curr=curr->next;
            lenA++;
        }
        curr=headB;
        while(curr!=NULL)
        {
            curr=curr->next;
            lenB++;
        }
        
        while(lenA>lenB)
        {
            headA=headA->next;
            lenA--;
        }
        while(lenB>lenA)
        {
            headB=headB->next;
            lenB--;
        }
        
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};
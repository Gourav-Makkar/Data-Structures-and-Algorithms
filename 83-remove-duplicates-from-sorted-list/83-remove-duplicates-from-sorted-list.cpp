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
        ListNode*curr=head;
        ListNode* newHead=NULL,*tail=NULL;
        
        while(curr!=NULL)
        {
            if(newHead==NULL)
            {
                newHead=curr;
                tail=curr;
            }
            else
            {
                if(tail->val!=curr->val)
                {
                    tail->next=curr;
                    tail=tail->next;
                }
            }
            curr=curr->next;
        }
        if(tail!=NULL)
           tail->next=NULL;
        return newHead;
    }
};
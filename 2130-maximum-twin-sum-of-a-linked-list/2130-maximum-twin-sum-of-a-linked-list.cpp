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
     ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL,*curr=head,*nxt=NULL;
        
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    
    int pairSum(ListNode* head) {
        ListNode* slow=head,*fast=head;
        int ans=INT_MIN;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* c1=head,*c2=slow;
        
        c2=reverse(c2);
        
        while(c2)
        {
            ans=max(ans,c1->val+c2->val);
            c1=c1->next;
            c2=c2->next;
        }
        return ans;
    }
};
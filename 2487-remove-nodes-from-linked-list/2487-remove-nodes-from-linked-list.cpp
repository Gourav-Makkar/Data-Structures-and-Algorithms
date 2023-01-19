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
        while(curr!=NULL)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    
    ListNode* removeNodes(ListNode* head) {
        ListNode* h=NULL,*t=NULL;
        head=reverse(head);
        
        int mx=INT_MIN;
        ListNode* curr=head;
        
        while(curr!=NULL)
        {
            if(curr->val>=mx)
            {
                mx=curr->val;
                if(h==NULL)
                {
                    h=curr;
                    t=curr;
                }
                else
                {
                    t->next=curr;
                    t=t->next;
                }
            }
            curr=curr->next;
        }
        t->next=NULL;
        return reverse(h);
    }
};
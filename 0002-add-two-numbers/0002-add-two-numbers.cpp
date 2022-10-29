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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=NULL,*tail=NULL;
        int carry=0;
        while(l1!=NULL || l2!=NULL)
        {
            int data=0;
            if(l1!=NULL)
                data+=l1->val;
            if(l2!=NULL)
                data+=l2->val;
            data+=carry;
            ListNode* temp=new ListNode(data%10);
            carry=data/10;
            
            if(head==NULL)
            {
                head=temp;
                tail=temp;
            }
            else
            {
                tail->next=temp;
                tail=tail->next;
            }
            if(l1!=NULL)
                l1=l1->next;
            if(l2!=NULL)
               l2=l2->next;
        }
        if(carry!=0)
            tail->next=new ListNode(carry);
        
        return head;
        
    }
};
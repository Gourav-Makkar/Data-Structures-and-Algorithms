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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *head1=NULL,*tail=NULL;
        ListNode* curr=head->next;
        long long sum=0;
        while(curr!=NULL)
        {
            if(curr->val==0)
            {
                ListNode* temp=new ListNode(sum);
                if(head1==NULL)
                {
                    head1=temp;
                    tail=temp;
                }
                else
                {
                    tail->next=temp;
                    tail=tail->next;
                }
                curr=curr->next;
                sum=0;
                continue;
            }
            sum+=curr->val;
            curr=curr->next;
        }
        return head1;
    }
};
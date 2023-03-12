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
    
    void mergetwo(ListNode* head1,ListNode* head2,ListNode* &head)
    {
        ListNode* tail=NULL;
        
        while(head1 && head2)
        {
            if(head1->val<=head2->val)
            {
                if(!head)
                {
                    head=head1;
                    tail=head1;
                }
                else
                {
                    tail->next=head1;
                    tail=tail->next;
                }
                head1=head1->next;
            }
            else
            {
                if(!head)
                {
                    head=head2;
                    tail=head2;
                }
                else
                {
                    tail->next=head2;
                    tail=tail->next;
                }
                head2=head2->next;
            }
        }
        if(tail==NULL)
        {
            if(!head1)
                head=head2;
            else
                head=head1;
        }
        else
        {
            if(!head1)
                tail->next=head2;
            else
                tail->next=head1;
        }
    }
    
    void merge(vector<ListNode*>&lists,int st,int en,ListNode* &head)
    {
        if(st==en)
        {
            ListNode* tail=NULL;
            ListNode* curr=lists[st];
            
            while(curr!=NULL)
            {
                if(!head)
                {
                    head=curr;
                    tail=curr;
                }
                else
                {
                    tail->next=curr;
                    tail=tail->next;
                }
                curr=curr->next;
            }
            return;
        }
        if(en-st==1)
        {
            mergetwo(lists[st],lists[en],head);
            return;
        }
        
        int mid=st+(en-st)/2;
        ListNode* head1=NULL,*head2=NULL;
        
        merge(lists,st,mid,head1);
        merge(lists,mid+1,en,head2);
        
        mergetwo(head1,head2,head);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
             return NULL;
        ListNode* head=NULL;
        
        merge(lists,0,lists.size()-1,head);
        return head;
    }
};
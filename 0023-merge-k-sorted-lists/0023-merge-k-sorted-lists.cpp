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
    
    void merge(ListNode* head1,ListNode* head2,ListNode* &head)
    {
        ListNode* tail=NULL;
        
        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val<head2->val)
            {
                if(head==NULL)
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
                if(head==NULL)
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
        
        if(head1==NULL)
        {
            if(head==NULL)
            {
                head=head2;
                tail=head2;
            }
            else
                tail->next=head2;
        }
        if(head2==NULL)
        {
            if(head==NULL)
            {
                head=head1;
                tail=head1;
            }
            else
                tail->next=head1;
        }
       
    }
    
    void mergeLists(vector<ListNode*>& lists,int st,int en,ListNode* &head)
    {
        ListNode* tail=NULL;
        if(st==en)
        {
            ListNode* curr=lists[st];
            while(curr!=NULL)
            {
                if(head==NULL)
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
            ListNode* head1=lists[st];
            ListNode* head2=lists[en];
            
            merge(head1,head2,head);
            return;
        }
        
        int mid=st+(en-st)/2;
        
        ListNode* head1=NULL,*head2=NULL;
        
        mergeLists(lists,st,mid,head1);
        mergeLists(lists,mid+1,en,head2);
        
        merge(head1,head2,head);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        ListNode* head=NULL;
        int n=lists.size();
        
        mergeLists(lists,0,n-1,head);
        
        return head;
    }
};
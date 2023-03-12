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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        
        for(auto it:lists)
        {
            if(it)
                pq.push({it->val,it});
        }
        
        ListNode* head=NULL,*tail=NULL;
        
        while(!pq.empty())
        {
            int val=pq.top().first;
            ListNode* curr=pq.top().second;
            
            pq.pop();
            
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
            
            if(curr->next)
                pq.push({curr->next->val,curr->next});
        }
        return head;
     }
};
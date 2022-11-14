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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans;
        int ct=0;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            ct++;
            curr=curr->next;
        }
        int q=ct/k;
        int rem=ct%k;
        
        curr=head;
        while(curr!=NULL)
        {
            ans.push_back(curr);
            int l=1;
            while(l<q)
            {
                l++;
                curr=curr->next;
            }
            if(rem>0 && ct>k)
            {
                curr=curr->next;
                rem--;
            }
            ListNode* temp=curr->next;
            curr->next=NULL;
            curr=temp;
        }
        while(ans.size()<k)
            ans.push_back(NULL);
        
        return ans;
    }
};
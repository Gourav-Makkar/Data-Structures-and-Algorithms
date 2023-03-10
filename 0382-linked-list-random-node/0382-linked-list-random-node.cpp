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
    vector<int>temp;
    Solution(ListNode* head) {
        ListNode* curr=head;
        
        while(curr!=NULL)
        {
            temp.push_back(curr->val);
            curr=curr->next;
        }
    }
    
    int getRandom() {
        int idx=rand()%temp.size();
        
        return temp[idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
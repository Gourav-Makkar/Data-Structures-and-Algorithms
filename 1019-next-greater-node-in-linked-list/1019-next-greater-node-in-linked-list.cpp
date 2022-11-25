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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>v;
        ListNode*curr=head;
        while(curr!=NULL)
        {
            v.push_back(curr->val);
            curr=curr->next;
        }
        int n=v.size();
        vector<int>ans(n);
        
        stack<int>st;
        ans[n-1]=0;
        st.push(v[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && st.top()<=v[i])
                st.pop();
            int x=(st.empty())?0:st.top();
            ans[i]=x;
            st.push(v[i]);
        }
        
        return ans;
    }
};
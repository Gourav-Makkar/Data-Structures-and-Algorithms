class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        stack<int>st;
        vector<int>nextGr(n);
        nextGr[n-1]=-1;
        st.push(nums2[n-1]);
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums2[i]>=st.top())
                st.pop();
            int ele=(st.empty())?-1:st.top();
            nextGr[i]=ele;
            st.push(nums2[i]);
        }
        int s=nums1.size();
        vector<int>ans(s);
        
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(nums2[j]==nums1[i])
                {
                    ans[i]=nextGr[j];
                }
            }
        }
        return ans;
    }
};
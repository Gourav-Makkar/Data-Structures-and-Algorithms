class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        stack<int>st;
        int n=nums2.size();
        unordered_map<int,int>m;
        
        st.push(nums2[n-1]);
        m[nums2[n-1]]=-1;
        
        for(int i=n-2;i>=0;i--)
        {
            while(!st.empty() && nums2[i]>=st.top())
                st.pop();
            int ele=(st.empty())?-1:st.top();
            m[nums2[i]]=ele;
            st.push(nums2[i]);
        }
             
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(m[nums1[i]]);
        }
        
        return ans;
    }
};
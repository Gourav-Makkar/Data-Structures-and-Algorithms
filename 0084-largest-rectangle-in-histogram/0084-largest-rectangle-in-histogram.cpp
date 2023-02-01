class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nextsm(n);
        stack<int>st;
        
        nextsm[n-1]=n;
        st.push(n-1);
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            int idx=st.empty()?n:st.top();
            nextsm[i]=idx;
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        vector<int>prevsm(n);
        prevsm[0]=-1;
        st.push(0);
        
        for(int i=1;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            int idx=st.empty()?-1:st.top();
            prevsm[i]=idx;
            st.push(i);
        }
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            int prev=prevsm[i];
            int next=nextsm[i];
            
            ans=max(ans,(next-prev-1)*heights[i]);
        }
        return ans;
    }
};
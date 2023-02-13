class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>ans(n);
        stack<int>st;
        ans[n-1]=0;
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--)
        {
            int ct=0;
            while(!st.empty() && heights[i]>heights[st.top()])
            {
                ct++;
                st.pop();
            }
            
            int curr=(st.empty())?ct: ct+1;
            ans[i]=curr;
            st.push(i);
        }
        return ans;
    }
};
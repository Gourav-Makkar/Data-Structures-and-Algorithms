class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int>ans(n);
        
        ans[n-1]=0;
        stack<int>st;
        st.push(heights[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            int ct=0;
            while(!st.empty() && st.top()<heights[i])
            {
                st.pop();
                ct++;
            }
            int res=(st.empty())?ct:ct+1;
            ans[i]=res;
            st.push(heights[i]);
        }
        
        return ans;
    }
};
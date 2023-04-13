class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int n=pushed.size(),m=popped.size(),idx=0;
        
        for(int i=0;i<n;i++)
        {
            st.push(pushed[i]);
            if(st.top()==popped[idx])
            {
                while(!st.empty() && st.top()==popped[idx])
                {
                    st.pop();
                    idx++;
                }
            }
        }
        return idx==m && st.empty();
    }
};
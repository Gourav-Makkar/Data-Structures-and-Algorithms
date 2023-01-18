class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        
        stack<int>st;
        int i=0,j=0;
        
        while(j<n)
        {
            if(i<n && st.empty())
            {
                st.push(pushed[i++]);
                continue;
            }
            if(st.top()!=popped[j])
            {
                if(i==n)
                    break;
                st.push(pushed[i++]);
            }
            else if(st.top()==popped[j])
            {
                st.pop();
                j++;
            }
        }
        return j==n;
    }
};
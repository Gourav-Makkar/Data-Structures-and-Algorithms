class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>st;
        
        for(int i=0;i<n;i++)
        {
            if(st.size()==0)
            {
                st.push(s[i]);
                continue;
            }
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                st.push(s[i]);
                continue;
            }
            
            if(s[i]==')')
            {
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else
                    return false;
            }
               
            if(s[i]==']')
            {
                if(!st.empty() && st.top()=='[')
                    st.pop();
                else
                    return false;
            }
           if(s[i]=='}')
            {
                if(!st.empty() && st.top()=='{')
                    st.pop();
                else
                    return false;
            }
        }
        
        return st.size()==0;
    }
};
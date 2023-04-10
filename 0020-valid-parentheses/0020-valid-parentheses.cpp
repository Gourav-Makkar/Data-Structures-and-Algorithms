class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='[')
            {
                st.push(ch);
                continue;
            }
            
            if(ch==')')
            {
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else
                    return false;
            }
            if(ch=='}')
            {
                if(!st.empty() && st.top()=='{')
                    st.pop();
                else
                    return false;
            }
            if(ch==']')
            {
               if(!st.empty() && st.top()=='[')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};
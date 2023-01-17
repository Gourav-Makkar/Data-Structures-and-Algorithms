class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        stack<char>st;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                if(st.size()!=0)
                   ans+=s[i];
                st.push(s[i]);
            }
             else
        {
           st.pop();
            if(st.size()!=0)
                ans+=s[i];
        }
        }
        return ans;
    }
};
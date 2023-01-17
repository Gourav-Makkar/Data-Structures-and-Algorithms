class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        stack<char>st;
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                if(st.size()!=0)
                    ans+=s[i];
                
                st.push(s[i]);
            }
            else
            {
                if(st.size()!=1)
                    ans+=s[i];
                st.pop();
            }
        }
        return ans;
    }
};
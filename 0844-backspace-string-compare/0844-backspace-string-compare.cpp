class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='#')
                st.push(s[i]);
            else if(!st.empty() && s[i]=='#')
                st.pop();
        }
        string t1="";
        
        while(!st.empty())
        {
            t1+=st.top();
            st.pop();
        }
        
        for(int i=0;i<t.size();i++)
        {
            if(t[i]!='#')
                st.push(t[i]);
            else if(!st.empty() && t[i]=='#')
                st.pop();
        }
        string t2="";
        
        while(!st.empty())
        {
            t2+=st.top();
            st.pop();
        }
        
        return t1==t2;
    }
};
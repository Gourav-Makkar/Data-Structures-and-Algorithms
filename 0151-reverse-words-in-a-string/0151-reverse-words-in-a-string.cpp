class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        
        string word="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!=' ')
                word+=s[i];
            if(s[i]==' ' && word!="")
            {
                st.push(word);
                word="";
            }
        }
        if(word!="")
            st.push(word);
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            ans+=' ';
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};
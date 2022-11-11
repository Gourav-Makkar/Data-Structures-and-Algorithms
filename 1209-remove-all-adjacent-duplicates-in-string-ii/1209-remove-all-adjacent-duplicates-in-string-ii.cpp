class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        
        for(int i=0;i<s.length();i++)
        {
            if(st.empty() || st.top().first!=s[i])
            {
                st.push({s[i],1});
            }
            else if(st.top().first==s[i])
            {
                int ct=st.top().second;
                st.push({s[i],ct+1});
                if(st.top().second==k)
                {
                    while(!st.empty() && st.top().first==s[i])
                        st.pop();
                }
            }
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
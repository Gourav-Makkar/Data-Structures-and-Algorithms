class Solution {
public:
    string removeDuplicates(string s, int k) {
       stack<pair<char,int>>st;
        int i=0;
        int n=s.size();
        while(i < n)
        {
            if(st.empty() || st.top().first != s[i]) st.push({s[i], 1});
            else if(!st.empty())
            {
                int topCount = st.top().second;
                if(st.top().first == s[i]) st.push({s[i], topCount+1});
                if(topCount+1 == k)
                {
                    int ct = k;
                    while(ct--) st.pop();
                }
            }
            i++;
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top().first;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
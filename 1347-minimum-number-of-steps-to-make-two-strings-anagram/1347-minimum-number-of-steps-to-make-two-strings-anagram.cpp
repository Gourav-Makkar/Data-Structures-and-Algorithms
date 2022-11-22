class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
        }
        
        int ct=0;
        for(int i=0;i<t.length();i++)
        {
            if(m.find(t[i])!=m.end())
            {
                m[t[i]]--;
                if(m[t[i]]==0)
                    m.erase(t[i]);
            }
            else
                ct++;
        }
        return ct;
    }
};
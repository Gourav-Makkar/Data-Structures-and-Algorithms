class Solution {
public:
    int minSteps(string s, string t) {
        multiset<char>m;
        for(int i=0;i<s.length();i++)
            m.insert(s[i]);
        int ct=0;
        for(int i=0;i<t.length();i++)
        {
            if(m.find(t[i])!=m.end())
                m.erase(m.find(t[i]));
            else
                ct++;
        }
        return ct+m.size();
    }
};
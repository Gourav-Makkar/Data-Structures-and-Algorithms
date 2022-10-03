class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>m1;
        for(int i=0;i<s.length();i++)
        {
            m1[s[i]]++;
        }
        unordered_map<char,int>m2;
        for(int i=0;i<t.length();i++)
        {
            m2[t[i]]++;
        }
        if(m1==m2)
            return true;
        return false;
    }
};
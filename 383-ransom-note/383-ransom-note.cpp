class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>m;
        for(int i=0;i<ransomNote.length();i++)
        {
            m[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.length();i++)
        {
            if(m.find(magazine[i])!=m.end())
            {
                m[magazine[i]]--;
                if(m[magazine[i]]==0)
                    m.erase(magazine[i]);
            }
        }
        if(m.size()==0)
            return true;
        return false;
    }
};
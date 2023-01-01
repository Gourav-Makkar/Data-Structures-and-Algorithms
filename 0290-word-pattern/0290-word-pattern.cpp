class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int p=pattern.length();
        int n=s.length();
        
        vector<string>v;
        unordered_map<char,vector<int>>m1;
        for(int i=0;i<p;i++)
          m1[pattern[i]].push_back(i);
        
        unordered_map<string,vector<int>>m2;
        
        string word="";
        int curr=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                m2[word].push_back(curr);
                v.push_back(word);
                curr++;
                word="";
            }
            else
                word+=s[i];
        }
        if(word!="")
        {
            v.push_back(word);
            m2[word].push_back(curr);
        }
        
        if(m1.size()!=m2.size())
            return false;
        
        for(int i=0;i<p;i++)
        {
            if(m1[pattern[i]]!=m2[v[i]])
                return false;
        }
        return true;
    }
};
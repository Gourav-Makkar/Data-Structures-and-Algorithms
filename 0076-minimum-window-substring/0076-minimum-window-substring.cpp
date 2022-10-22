class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(int i=0;i<t.length();i++)
        {
            m[t[i]]++;
        }
        int count=m.size();
        int n=s.length();
        int i=0,j=0;
        string ans="";
        while(j<n)
        {
            if(m.find(s[j])!=m.end())
            {
                m[s[j]]--;
                if(m[s[j]]==0)
                  count--;
            }
            if(count==0)
            {
                while(count==0)
                {
                    if(ans.length()==0 || j-i+1<ans.length())
                    {
                        ans=s.substr(i,j-i+1);
                    }
                    if(m.find(s[i])!=m.end())
                    {
                      m[s[i]]++;
                      if(m[s[i]]>=1)
                        count++;
                    }
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};
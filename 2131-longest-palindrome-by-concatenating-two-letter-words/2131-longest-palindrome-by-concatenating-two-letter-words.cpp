class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        string ans="";
        unordered_map<string,int>m;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            m[words[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            string s=words[i];
            if(s[0]!=s[1])
            {
                string rev=s;
                reverse(rev.begin(),rev.end());
                if(m[s]>0 && m[rev]>0)
                {
                    ans+=s;
                    ans+=rev;
                    
                    m[s]--;
                    m[rev]--;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            string s=words[i];
            if(s[0]==s[1])
            {
                if(m[s]%2!=0)
                {
                    while(m[s]!=0)
                    {
                        ans+=s;
                        m[s]--;
                    }
                    break;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            string s=words[i];
            if(s[0]==s[1])
            {
                if(m[s]%2!=0)
                {
                    while(m[s]!=1)
                    {
                        ans+=s;
                        m[s]--;
                    }
                }
                else
                {
                    while(m[s]!=0)
                    {
                        ans+=s;
                        m[s]--;
                    }
                }
            }
        }
        
        return ans.length();
    }
};
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,int>m1,m2;
        
        for(int i=0;i<chars.size();i++)
          m1[chars[i]]=i;
        
        for(auto it:s)
        {
            if(m1.find(it)!=m1.end())
                m2[it]=vals[m1[it]];
            else
                m2[it]=(it-'a') + 1;
        }
        
        int ans=m2[s[0]],cs=m2[s[0]];
        
        for(int i=1;i<s.size();i++)
        {
            if(cs+m2[s[i]]<m2[s[i]])
                cs=m2[s[i]];
            else
                cs+=m2[s[i]];
            
            ans=max(ans,cs);
        }
        if(ans<0)
            return 0;
        return ans;
    }
};
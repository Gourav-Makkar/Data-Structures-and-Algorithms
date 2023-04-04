class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        unordered_map<char,int>m;
        
        int i=0,j=0,ans=0;
        while(j<n)
        {
            m[s[j]]++;
            
            if(j-i+1!=m.size())
            {
                m.clear();
                m[s[j]]++;
                i=j;
                ans++;
            }
            j++;
        }
        if(m.size()!=0)
            ans++;
        return ans;
    }
};
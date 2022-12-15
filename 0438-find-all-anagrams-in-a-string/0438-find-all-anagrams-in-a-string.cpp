class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int>m1,m2;
        int n=s.length(),m=p.length();
        
        if(m>n)
            return ans;
        
        for(int i=0;i<m;i++)
        {
            m1[p[i]]++;
        }
        
        int i=0,j=0;
        
        while(j<n)
        {
            m2[s[j]]++;
            if(j-i+1==m)
            {
                if(m1==m2)
                    ans.push_back(i);
                m2[s[i]]--;
                if(m2[s[i]]==0)
                    m2.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};
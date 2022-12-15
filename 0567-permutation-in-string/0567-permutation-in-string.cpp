class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>m1,m2;
        int n=s2.length(),m=s1.length();
        
        if(m>n)
            return false;
        
        for(int i=0;i<m;i++)
        {
            m1[s1[i]]++;
        }
        
        int i=0,j=0;
        
        while(j<n)
        {
            m2[s2[j]]++;
            if(j-i+1==m)
            {
                if(m1==m2)
                    return true;
                m2[s2[i]]--;
                if(m2[s2[i]]==0)
                    m2.erase(s2[i]);
                i++;
            }
            j++;
        }
        return false;
    }
};
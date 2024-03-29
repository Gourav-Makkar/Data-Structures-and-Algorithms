class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0;
        
        unordered_map<int,int>m;
        int ans=0;
        while(j<n)
        {
            m[s[j]]++;
            
            while(m.size()<j-i+1)
            {
                m[s[i]]--;
                if(m[s[i]]==0)
                    m.erase(s[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
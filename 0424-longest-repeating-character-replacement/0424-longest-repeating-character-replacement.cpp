class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int>m;
        int i=0,j=1;
        m[s[0]]++;
        int mx=1;
        int ans=1;
        while(j<n)
        {
            m[s[j]]++;
            mx=max(mx,m[s[j]]);
            
            if((j-i+1) - mx <= k)
                ans=max(ans,j-i+1);
            else
            {
                while((j-i+1) - mx > k)
                {
                    m[s[i]]--;
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};
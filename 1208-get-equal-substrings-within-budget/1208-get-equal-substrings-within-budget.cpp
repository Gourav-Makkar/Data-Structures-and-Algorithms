class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        int ans=0;
        
        int i=0,j=0;
        int cc=0;
        
        while(j<n)
        {
           cc+=abs(s[j]-t[j]);
        
           if(cc<=maxCost)
               ans=max(ans,j-i+1);
           else 
           {
               while(cc>maxCost)
               {
                   cc-=abs(s[i]-t[i]);
                   i++;
               }
           }
            j++;
        }
        return ans;
    }
};
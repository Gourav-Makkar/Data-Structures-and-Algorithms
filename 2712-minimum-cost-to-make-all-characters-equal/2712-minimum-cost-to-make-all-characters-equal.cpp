class Solution {
public:
    long long minimumCost(string s) {
        int n=s.size();
        
        long long ans=0;
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i]!=s[i+1])
                ans=ans+min(i+1,n-i-1);
        }
        return ans;
    }
};
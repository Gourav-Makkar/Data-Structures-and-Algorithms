class Solution {
public:
    
    int helper(int idx,string &s,int prev,int n,vector<vector<int>>&dp)
    {
        if(idx==n)
            return 0;
        
        if(dp[idx][prev]!=-1)
            return dp[idx][prev];
        
        int f=0,nf=0;
        
        if(prev==0)
        {
            if(s[idx]=='0')
            {
                nf=0+helper(idx+1,s,0,n,dp);
                f=1+helper(idx+1,s,1,n,dp);
            }
            else
            {
                nf=0+helper(idx+1,s,1,n,dp);
                f=1+helper(idx+1,s,0,n,dp);
            }
        }
        else
        {
            if(s[idx]=='0')
              return dp[idx][prev]=1+helper(idx+1,s,1,n,dp);
            else
              return dp[idx][prev]=0+helper(idx+1,s,1,n,dp);
        }
        
        return dp[idx][prev]=min(f,nf);
    }
    
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        
        vector<vector<int>>dp(n,vector<int>(2,-1));
        
        return helper(0,s,0,n,dp);
    }
};
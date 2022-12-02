class Solution {
public:
    int mod=1e9+7;
    int helper(string s,string t,int idx1,int idx2,vector<vector<int>>&dp)
    {
        if(idx2==0)
            return 1;
        if(idx1==0)
            return 0;
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        int ct=0;
        if(s[idx1-1]==t[idx2-1])
            ct+=helper(s,t,idx1-1,idx2-1,dp);
        ct+=helper(s,t,idx1-1,idx2,dp);
        
        return dp[idx1][idx2]=ct;
    }
    
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return helper(s,t,n,m,dp);
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        for(int i=1;i<=m;i++)
            dp[0][i]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int ct=0;
                if(s[i-1]==t[j-1])
                    ct+=(dp[i-1][j-1])%mod;
                ct+=(dp[i-1][j])%mod;
                
                dp[i][j]=ct;
            }
        }
        return dp[n][m];
    }
};
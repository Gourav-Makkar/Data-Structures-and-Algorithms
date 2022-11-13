class Solution {
public:
    int mod=1e9+7;
    int helper(string s,string t,int i,int j,vector<vector<int>>&dp)
    {
        if(j==0)
            return 1;
        if(i==0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int take=0,notTake=0,notMatch=0;
        if(s[i-1]==t[j-1])
        {
            take=helper(s,t,i-1,j-1,dp);
            notTake=helper(s,t,i-1,j,dp);
        }
        else
            notMatch=helper(s,t,i-1,j,dp);
        return dp[i][j]=take+notTake+notMatch;
    }
    
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return helper(s,t,n,m,dp);
        
        for(int i=0;i<=m;i++)
            dp[0][i]=0;
        
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int take=0,notTake=0,notMatch=0;
                if(s[i-1]==t[j-1])
                {
                    take=dp[i-1][j-1];
                    notTake=dp[i-1][j];
                }
                else
                    notMatch=dp[i-1][j];
                dp[i][j]=(take+notTake+notMatch)%mod;
            } 
        }
        return dp[n][m];
        
    }
};
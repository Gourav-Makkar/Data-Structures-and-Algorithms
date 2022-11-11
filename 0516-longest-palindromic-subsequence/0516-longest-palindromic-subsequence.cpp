class Solution {
public:
    
    // int helper(string s,int idx1,int idx2,vector<vector<int>>&dp)
    // {
    //     if(idx1>idx2)
    //         return 0;
    //     if(idx1==idx2)
    //         return 1;
    //     if(dp[idx1][idx2]!=-1)
    //         return dp[idx1][idx2];
    //     if(s[idx1]==s[idx2])
    //         return dp[idx1][idx2] = 2 + helper(s,idx1+1,idx2-1,dp);
    //     return dp[idx1][idx2] = max(helper(s,idx1+1,idx2,dp),helper(s,idx1,idx2-1,dp));
    // }
    
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string s2=s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};
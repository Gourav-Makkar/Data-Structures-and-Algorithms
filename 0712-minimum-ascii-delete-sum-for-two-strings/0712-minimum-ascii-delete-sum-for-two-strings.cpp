class Solution {
public:
    
    int helper(string s1,string s2,int idx1,int idx2,vector<vector<int>>&dp)
    {
        if(idx1==0 || idx2==0)
            return 0;
        
        if(dp[idx1][idx2]!=-1)
            return dp[idx1][idx2];
        
        if(s1[idx1-1]==s2[idx2-1])
            return s1[idx1-1]+helper(s1,s2,idx1-1,idx2-1,dp);
        
        return dp[idx1][idx2]=max(helper(s1,s2,idx1-1,idx2,dp),helper(s1,s2,idx1,idx2-1,dp));
    }
    
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // int val=helper(s1,s2,n,m,dp);
        
        int total=0;
        for(int i=0;i<n;i++)
            total+=s1[i];
        for(int i=0;i<m;i++)
            total+=s2[i];
        
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int i=0;i<=m;i++)
            dp[0][i]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=s1[i-1]+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int val=dp[n][m];
        
        return total-2*val;
    }
};
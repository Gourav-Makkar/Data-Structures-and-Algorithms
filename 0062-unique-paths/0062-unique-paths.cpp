class Solution {
public:
    
//     MEMOIZATION
    
//     int helper(int dr,int dc,vector<vector<int>>&dp)
//     {
//         if(dr==0 && dc==0)
//             return 1;
//         if(dr<0 || dc<0)
//             return 0;
        
//         if(dp[dr][dc]!=-1)
//             return dp[dr][dc];
//         int up=helper(dr-1,dc,dp);
//         int left=helper(dr,dc-1,dp);
        
//         return dp[dr][dc]=up+left;   
        
//     }
   
    int uniquePaths(int m, int n) {
        
        // int dr=m-1,dc=n-1;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // int ans=0;
        // ans+=helper(dr,dc,dp);
        // return ans;
        
        for(int i=0;i<m;i++)
        {
            dp[i][0]=1;
        }
        for(int i=0;i<n;i++)
        {
            dp[0][i]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
       return dp[m-1][n-1];
    }
};
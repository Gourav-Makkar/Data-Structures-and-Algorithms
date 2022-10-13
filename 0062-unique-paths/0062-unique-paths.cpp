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
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // int ans=0;
        // ans+=helper(dr,dc,dp);
        // return ans;
   
//       TABULATION  
       //  for(int i=0;i<m;i++)
       //  {
       //      for(int j=0;j<n;j++)
       //      {
       //          if(i==0 && j==0)
       //          {
       //              dp[i][j]=1;  //BASE CASE
       //              continue;
       //          }
       //          int up=0,left=0;
       //          if(i>0)
       //              up=dp[i-1][j];
       //          if(j>0)
       //              left=dp[i][j-1];
       //          dp[i][j]=up+left;
       //      }
       //  }
       // return dp[m-1][n-1];
        
        
//         SPACE OPTIMIZED
        
        vector<int>dp(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int>temp(n,0);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    temp[j]=1;
                    continue;
                }
                int up=dp[j];
                int left=0;
                if(j>0)
                    left=temp[j-1];

                temp[j]=up+left;
            }
            dp=temp;
        }
        return dp[n-1];
        
    }
};
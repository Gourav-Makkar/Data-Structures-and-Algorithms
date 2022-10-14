class Solution {
public:
    
//     MEMOIZATION
    
//     int helper(vector<vector<int>>&triangle,int i,int j,int n,vector<vector<int>>&dp)
//     {
//         if(i==n-1)
//         {
//             return triangle[i][j];
//         }
//         if(dp[i][j]!=-1)
//             return dp[i][j];
//         int down=triangle[i][j]+helper(triangle,i+1,j,n,dp);
        
//         int diag=triangle[i][j]+helper(triangle,i+1,j+1,n,dp);
        
//         return dp[i][j]=min(down,diag);
//     }
    
//     TABULATION
    int minimumTotal(vector<vector<int>>& triangle) {
       int n=triangle.size();
       vector<vector<int>>dp(n,vector<int>(n,-1));
       // return helper(triangle,0,0,n,dp);
        
       for(int i=n-1;i>=0;i--)
       {
           for(int j=i;j>=0;j--)
           {
               if(i==n-1)
               {
                   dp[i][j]=triangle[i][j];
                   continue;
               }
               int down=triangle[i][j]+ dp[i+1][j];
               int diag=triangle[i][j]+dp[i+1][j+1];
               
               dp[i][j]=min(down,diag);
           }
       }
    return dp[0][0];
    }
};
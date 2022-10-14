class Solution {
public:
     
//     MEMOIZATION
    
//     int helper(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp)
//     {
//         if(i<0 || j<0)
//             return 1000;
//         if(i==0 && j==0)
//         {
//             return grid[i][j];
//         }
//         if(dp[i][j]!=-1)
//             return dp[i][j];
       
//         int up= grid[i][j]+helper(grid,i-1,j,dp);
//         int left= grid[i][j]+helper(grid,i,j-1,dp);
        
//         return dp[i][j]=min(up,left);
//     }    
    
//     TABULATION
    
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        
        // return helper(grid,m-1,n-1,dp);
        
//         dp[0][0]=grid[0][0];
//         for(int i=0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(i==0 && j==0)
//                     continue;
//                 int up=grid[i][j],left=grid[i][j];
//                 if(i==0)
//                     up+=1000;
//                 else 
//                     up+=dp[i-1][j];
//                 if(j==0)
//                     left+=1000;
//                 else
//                     left+=dp[i][j-1];
                
//                 dp[i][j]=min(up,left);
//             }
//         }
//         return dp[m-1][n-1];
        
        vector<int>prev(n,1000);
        for(int i=0;i<m;i++)
        {
            vector<int>curr(n);
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                {
                    curr[j]=grid[i][j];
                    continue;
                }
                int up=grid[i][j],left=grid[i][j];
                if(i>0)
                    up+=prev[j];
                else
                    up+=1000;
                if(j>0)
                    left+=curr[j-1];
                else
                    left+=1000;
                
                curr[j]=min(up,left);
            }
            prev=curr;
        }
        return prev[n-1];
    }
};
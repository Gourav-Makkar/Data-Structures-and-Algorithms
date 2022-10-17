class Solution {
public:
    
//    MEMOIZATION
    // int helper(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp)
    // {
    //     if(j<0 || j>=grid[0].size())
    //         return 1e9;
    //     if(i==grid.size()-1)
    //         return grid[i][j];
    //     int val=INT_MAX;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     for(int k=0;k<grid[0].size();k++)
    //     {
    //         if(k==j)
    //             continue;
    //         val=min(val,grid[i][j]+helper(grid,i+1,k,dp));
    //     }
    //     return dp[i][j]=val;
    // }
    
//     TABULATION
    int minFallingPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));
        int ans=INT_MAX;
        // for(int i=0;i<c;i++)
        // {
        //     ans=min(ans,helper(grid,0,i,dp));
        // }
        // return ans;
        
        for(int i=0;i<c;i++)
        {
            dp[r-1][i]=grid[r-1][i];
        }
        
        for(int i=r-2;i>=0;i--)
        {
            for(int j=0;j<c;j++)
            {
                int val=INT_MAX;
                for(int k=0;k<c;k++)
                {
                    if(k==j)
                        continue;
                    val=min(val,grid[i][j]+dp[i+1][k]);
                }
                dp[i][j]=val;
            }
        }
        for(int i=0;i<c;i++)
        {
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};
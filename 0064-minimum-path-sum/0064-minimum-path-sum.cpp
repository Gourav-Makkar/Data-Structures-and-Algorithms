class Solution {
public:
    
    int helper(int cr,int cc,vector<vector<int>>&grid,int n,int m,vector<vector<int>>&dp)
    {
        if(cr==n || cr<0 || cc<0 || cc==m)
            return 1e9;
        
        if(cr==n-1 && cc==m-1)
            return grid[cr][cc];
        
        if(dp[cr][cc]!=-1)
            return dp[cr][cc];
        
        int down=grid[cr][cc]+helper(cr+1,cc,grid,n,m,dp);
        int right=grid[cr][cc]+helper(cr,cc+1,grid,n,m,dp);
        
        return dp[cr][cc]=min(down,right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        // return helper(0,0,grid,n,m,dp);
        int cs=0;
        
        for(int i=0;i<n;i++)
        {
            cs+=grid[i][0];
            dp[i][0]=cs;
        }
        cs=0;
        for(int i=0;i<m;i++)
        {
            cs+=grid[0][i];
            dp[0][i]=cs;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }
         return dp[n-1][m-1];   
    }
};
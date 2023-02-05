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
        
        return helper(0,0,grid,n,m,dp);
    }
};
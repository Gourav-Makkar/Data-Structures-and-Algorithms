class Solution {
public:
    
    int helper(int cr,int cc,vector<vector<int>>&grid,vector<vector<int>>&vis,vector<vector<int>>&dp)
    {
        int n=grid.size(),m=grid[0].size();
        
        if(cr==n || cc==m || vis[cr][cc])
            return 1e9;
        if(cr==n-1 && cc==m-1)
            return grid[cr][cc];
        
        if(dp[cr][cc]!=-1)
            return dp[cr][cc];
        
        vis[cr][cc]=1;
        
        int down=grid[cr][cc]+helper(cr+1,cc,grid,vis,dp);
        int right=grid[cr][cc]+helper(cr,cc+1,grid,vis,dp);
        
        vis[cr][cc]=0;
        return dp[cr][cc]=min(down,right);
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        return helper(0,0,grid,vis,dp);
    }
};
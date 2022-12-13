class Solution {
public:
    
    int helper(vector<vector<int>>&grid,int cr,int cc,int n,vector<vector<int>>&dp)
    {
        if(cr==n-1)
            return grid[cr][cc];
        
        if(dp[cr][cc]!=-1)
            return dp[cr][cc];
        
        int temp=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(i!=cc)
                temp=min(temp,grid[cr][cc]+helper(grid,cr+1,i,n,dp));
        }
        return dp[cr][cc]=temp;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            ans=min(ans,helper(grid,0,i,n,dp));
        }
        
        return ans;
    }
};
class Solution {
public:
    
    int helper(vector<vector<int>>&grid,int i,int j,vector<vector<int>>&dp)
    {
        if(j<0 || j>=grid[0].size())
            return 1e9;
        if(i==grid.size()-1)
            return grid[i][j];
        int val=INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(int k=0;k<grid[0].size();k++)
        {
            if(k==j)
                continue;
            val=min(val,grid[i][j]+helper(grid,i+1,k,dp));
        }
        return dp[i][j]=val;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));
        int ans=INT_MAX;
        for(int i=0;i<c;i++)
        {
            ans=min(ans,helper(grid,0,i,dp));
        }
        return ans;
    }
};
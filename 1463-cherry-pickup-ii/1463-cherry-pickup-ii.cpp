class Solution {
public:
    
    int helper(vector<vector<int>>&grid,int i,int j1,int j2,int r,int c,vector<vector<vector<int>>>&dp)
    {
        if(j1<0 || j1>=c || j2<0 || j2>=c)
            return -1e8;
        if(i==r-1)
        {
            if(j1==j2)
            {
                return grid[i][j1];
            }
            else
                return grid[i][j1]+grid[i][j2];
        }
        int ans=INT_MIN;
        
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            {
                if(j1==j2)
                {
                    ans=max(ans,grid[i][j1] + helper(grid,i+1,j1+dj1,j2+dj2,r,c,dp));
                }
                else
                {
                    ans=max(ans,grid[i][j1] + grid[i][j2] + helper(grid,i+1,j1+dj1,j2+dj2,r,c,dp));
                }
            }
        }
        return dp[i][j1][j2]=ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return helper(grid,0,0,c-1,r,c,dp);
    }
};
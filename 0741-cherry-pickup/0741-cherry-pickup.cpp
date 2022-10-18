class Solution {
public:
    
    int helper(vector<vector<int>>&grid,int i1,int i2,int j1,int j2,int n,vector<vector<vector<vector<int>>>>&dp)
    {
        if(i1>=n || i2>=n || j1>=n || j2>=n)
            return -1e8;
        if(grid[i1][j1]==-1 || grid[i2][j2]==-1)
            return -1e8;
        if(i1==n-1 && j1==n-1)
            return grid[i1][j1];
        if(i2==n-1 && j2==n-1)
            return grid[i2][j2];
        
        if(dp[i1][i2][j1][j2]!=-1)
            return dp[i1][i2][j1][j2];
        int cherry=0;
        if(i1==i2 && j1==j2)
            cherry=grid[i1][j1];
        else
            cherry=grid[i1][j1]+grid[i2][j2];
        
        int dd=helper(grid,i1+1,i2+1,j1,j2,n,dp);
        int dr=helper(grid,i1+1,i2,j1,j2+1,n,dp);
        int rd=helper(grid,i1,i2+1,j1+1,j2,n,dp);
        int rr=helper(grid,i1,i2,j1+1,j2+1,n,dp);
        
        int mx=max(dd,max(dr,max(rd,rr)));
        cherry+=mx;
        
        return dp[i1][i2][j1][j2]=cherry;
            
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==-1 || grid[n-1][n-1]==-1)
            return 0;
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        int ans=helper(grid,0,0,0,0,n,dp);
        if(ans<0)
            return 0;
        return ans;
    }
};
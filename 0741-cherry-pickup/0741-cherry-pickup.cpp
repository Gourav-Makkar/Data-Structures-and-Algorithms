class Solution {
public:
    
    int helper(int r1,int c1,int c2,vector<vector<int>>&grid,int n,vector<vector<vector<int>>>&dp)
    {
        int r2=r1+c1-c2;
        if(r1==n || c1==n || r2==n || c2==n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return -1e9;
        
        if(r1==n-1 && c1==n-1)
            return grid[r1][c1];
        if(r2==n-1 && c2==n-1)
            return grid[r2][c2];
        
        if(dp[r1][c1][c2]!=-1)
            return dp[r1][c1][c2];
        
        int ans=0;
        
        if(r1==r2 && c1==c2)
            ans=grid[r1][c1];
        else
            ans=grid[r1][c1]+grid[r2][c2];
        
        int dd=helper(r1+1,c1,c2,grid,n,dp);
        int dr=helper(r1+1,c1,c2+1,grid,n,dp);
        int rd=helper(r1,c1+1,c2,grid,n,dp);
        int rr=helper(r1,c1+1,c2+1,grid,n,dp);
    
        return dp[r1][c1][c2]=max(dd,max(dr,max(rd,rr)))+ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int ans=helper(0,0,0,grid,n,dp);
        if(ans<0)
            return 0;
        return ans;
    }
};
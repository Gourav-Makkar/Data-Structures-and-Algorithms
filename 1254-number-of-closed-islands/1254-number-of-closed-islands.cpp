class Solution {
public:
    
    void dfs(int cr,int cc,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        int n=grid.size(),m=grid[0].size();
        
        if(cr<0 || cr==n || cc<0 || cc==m || grid[cr][cc]==1 || vis[cr][cc]==1)
            return;
        vis[cr][cc]=1;
        
        dfs(cr+1,cc,grid,vis);
        dfs(cr,cc+1,grid,vis);
        dfs(cr-1,cc,grid,vis);
        dfs(cr,cc-1,grid,vis);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        
        vector<vector<int>>vis(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
        {
            if(grid[i][0]==0)
                dfs(i,0,grid,vis);
            
            if(grid[i][c-1]==0)
                dfs(i,c-1,grid,vis);
        }
        
        for(int i=0;i<c;i++)
        {
            if(grid[0][i]==0)
                dfs(0,i,grid,vis);
            
            if(grid[r-1][i]==0)
                dfs(r-1,i,grid,vis);
        }
        
        int ans=0;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(vis[i][j]==0 && grid[i][j]==0)
                {
                    ans++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
};
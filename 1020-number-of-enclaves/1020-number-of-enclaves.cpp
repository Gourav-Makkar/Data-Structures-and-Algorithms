class Solution {
public:
    
    void dfs(int cr,int cc,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        int n=grid.size(),m=grid[0].size();
        
        if(cr<0 || cr==n || cc<0 || cc==m || grid[cr][cc]==0 || vis[cr][cc]==1)
            return ;
        
        vis[cr][cc]=1;
        
        dfs(cr-1,cc,grid,vis);
        dfs(cr,cc+1,grid,vis);
        dfs(cr+1,cc,grid,vis);
        dfs(cr,cc-1,grid,vis);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
                dfs(i,0,grid,vis);
            
            if(grid[i][m-1]==1)
                dfs(i,m-1,grid,vis);
        }
        
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1)
                dfs(0,i,grid,vis);
            
            if(grid[n-1][i]==1)
                dfs(n-1,i,grid,vis);
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                    ans++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    
    void dfs(vector<vector<int>>&grid,int cr,int cc,int r,int c,vector<vector<int>>&vis)
    {
        if(cr<0 || cr==r || cc<0 || cc==c || grid[cr][cc]==0 || vis[cr][cc]==1)
            return;
        
        vis[cr][cc]=1;
        
        dfs(grid,cr-1,cc,r,c,vis);
        dfs(grid,cr,cc+1,r,c,vis);
        dfs(grid,cr+1,cc,r,c,vis);
        dfs(grid,cr,cc-1,r,c,vis);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int ans=0;
        
        vector<vector<int>>vis(r,vector<int>(c,0));
        
        // First Row
        for(int i=0;i<c;i++)
        {
            if(grid[0][i]==1)
                dfs(grid,0,i,r,c,vis);
        }
        
        //Last Column
        for(int i=0;i<r;i++)
        {
            if(grid[i][c-1]==1)
                dfs(grid,i,c-1,r,c,vis);
        }
        
        //Last Row
        for(int i=0;i<c;i++)
        {
            if(grid[r-1][i]==1)
                dfs(grid,r-1,i,r,c,vis);
        }
        
        //First Column
        for(int i=0;i<r;i++)
        {
            if(grid[i][0]==1)
                dfs(grid,i,0,r,c,vis);
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                    ans++;
            }
        }
        
        return ans;
    }
};
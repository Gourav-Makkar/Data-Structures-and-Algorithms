class Solution {
public:
    
    int dfs(vector<vector<int>>&grid,int cr,int cc,int r,int c,vector<vector<int>>&vis)
    {
        if(cr<0 || cc<0 || cr==r || cc==c || grid[cr][cc]==0 || vis[cr][cc]==1)
            return 0;
        
        int ct=1;
        vis[cr][cc]=1;
        
        ct+=dfs(grid,cr-1,cc,r,c,vis)+dfs(grid,cr,cc+1,r,c,vis)+dfs(grid,cr+1,cc,r,c,vis)+dfs(grid,cr,cc-1,r,c,vis);
        
        return ct;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        vector<vector<int>>vis(r,vector<int>(c,0));
        int ans=0;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                    ans=max(ans,dfs(grid,i,j,r,c,vis));
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    
    void dfs(int cr,int cc,vector<vector<char>>&grid,vector<vector<int>>&vis)
    {
        if(cr<0 || cr==grid.size() || cc<0 || cc==grid[0].size() || vis[cr][cc]==1 || grid[cr][cc]=='0')
            return;
        
        vis[cr][cc]=1;
        
        dfs(cr-1,cc,grid,vis);
        dfs(cr,cc+1,grid,vis);
        dfs(cr+1,cc,grid,vis);
        dfs(cr,cc-1,grid,vis);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size(); 
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    dfs(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;  
    }
};
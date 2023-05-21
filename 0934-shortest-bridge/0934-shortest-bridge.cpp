class Solution {
public:
    
    void dfs(int cr,int cc,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        if(cr<0 || cr==grid.size() || cc<0 || cc==grid[0].size() || vis[cr][cc] || grid[cr][cc]==0)
            return;
        
        vis[cr][cc]=1;
        
        dfs(cr-1,cc,grid,vis);
        dfs(cr,cc+1,grid,vis);
        dfs(cr+1,cc,grid,vis);
        dfs(cr,cc-1,grid,vis);   
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<vector<int>>q;
        bool flag=false;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(i,j,grid,vis);
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j])
                {
                    grid[i][j]=2;
                    vis[i][j]=0;
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty())
        {
            int cr=q.front()[0];
            int cc=q.front()[1];
            int dis=q.front()[2];
            
            q.pop();
            
            if(grid[cr][cc]==2)
                return dis-1;
            
            vector<int>temp={-1,0,1,0,-1};
            
            for(int i=1;i<5;i++)
            {
                int nr=cr+temp[i-1];
                int nc=cc+temp[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc])
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc,dis+1});
                }
            }
        }
        return -1;
    }
};
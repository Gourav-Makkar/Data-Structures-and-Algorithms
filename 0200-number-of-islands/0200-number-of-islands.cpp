class Solution {
public:
    
//     void dfs(vector<vector<char>>grid,int cr,int cc,int r,int c,vector<vector<int>>&vis)
//     {
//         if(cr<0 || cr==r || cc<0 || cc==c || grid[cr][cc]=='0' || vis[cr][cc]==1)
//             return;
        
//         vis[cr][cc]=1;
        
//         dfs(grid,cr-1,cc,r,c,vis);
//         dfs(grid,cr,cc+1,r,c,vis);
//         dfs(grid,cr+1,cc,r,c,vis);
//         dfs(grid,cr,cc-1,r,c,vis);
//     }
    
    void bfs(vector<vector<char>>grid,int cr,int cc,int r,int c,vector<vector<int>>&vis)
    {
        queue<pair<int,int>>q;
        q.push({cr,cc});
        vis[cr][cc]=1;
        
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            cr=p.first;
            cc=p.second;
            
            if(cr>0 && vis[cr-1][cc]!=1 && grid[cr-1][cc]=='1')
            {
                vis[cr-1][cc]=1;
                q.push({cr-1,cc});
            }
            
            if(cc<c-1 && vis[cr][cc+1]!=1 && grid[cr][cc+1]=='1')   
            {
                vis[cr][cc+1]=1;
                q.push({cr,cc+1});
            }
            
            if(cr<r-1 && vis[cr+1][cc]!=1 && grid[cr+1][cc]=='1')
            {
                vis[cr+1][cc]=1;
                q.push({cr+1,cc});
            }
            
            if(cc>0 && vis[cr][cc-1]!=1 && grid[cr][cc-1]=='1')
            {
                vis[cr][cc-1]=1;
                q.push({cr,cc-1});  
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    ans++;
                    bfs(grid,i,j,n,m,vis);
                }
            }
        }
        return ans;
    }
};
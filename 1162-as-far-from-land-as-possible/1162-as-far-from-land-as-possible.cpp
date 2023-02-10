class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    dis[i][j]=0;
                }
            }
        }
        
        while(!q.empty())
        {
            int cr=q.front().first.first;
            int cc=q.front().first.second;
            int d=q.front().second;
            
            q.pop();
            
            
            if(cr>0 && vis[cr-1][cc]==0 && grid[cr-1][cc]==0 && dis[cr-1][cc]>d+1)
            {
                q.push({{cr-1,cc},d+1});
                vis[cr-1][cc]=1;
                dis[cr-1][cc]=d+1;
            }
            
            if(cc<n-1 && vis[cr][cc+1]==0 && grid[cr][cc+1]==0 && dis[cr][cc+1]>d+1)
            {
                q.push({{cr,cc+1},d+1});
                vis[cr][cc+1]=1;
                dis[cr][cc+1]=d+1;
            }
            
            if(cr<n-1 && vis[cr+1][cc]==0 && grid[cr+1][cc]==0 && dis[cr+1][cc]>d+1)
            {
                q.push({{cr+1,cc},d+1});
                vis[cr+1][cc]=1;
                dis[cr+1][cc]=d+1;
            }
            
            if(cc>0 && vis[cr][cc-1]==0 && grid[cr][cc-1]==0 && dis[cr][cc-1]>d+1)
            {
                q.push({{cr,cc-1},d+1});
                vis[cr][cc-1]=1;
                dis[cr][cc-1]=d+1;
            }
            
        }
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    ans=max(ans,dis[i][j]);
            }
        }
        
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        if(grid[0][0]==1)
            return -1;
        
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        grid[0][0]=1;
        while(!q.empty())
        {
            pair<pair<int,int>,int>p=q.front();
            q.pop();
            
            int cr=p.first.first;
            int cc=p.first.second;
            int d=p.second;
            
            if(cr==n-1 && cc==n-1)
                return d;
            
            if(cr>0 && grid[cr-1][cc]!=1)
            {
                grid[cr-1][cc]=1;
                q.push({{cr-1,cc},d+1});
            }
            
            if(cr>0 && cc<n-1 && grid[cr-1][cc+1]!=1)
            {
                grid[cr-1][cc+1]=1;
                q.push({{cr-1,cc+1},d+1});
            }
            
            if(cc<n-1 && grid[cr][cc+1]!=1)
            {
                grid[cr][cc+1]=1;
                q.push({{cr,cc+1},d+1});
            }
            
            if(cr<n-1 && cc<n-1 && grid[cr+1][cc+1]!=1)
            {
                grid[cr+1][cc+1]=1;
                q.push({{cr+1,cc+1},d+1});
            }
            
            if(cr<n-1 && grid[cr+1][cc]!=1)
            {
                grid[cr+1][cc]=1;
                q.push({{cr+1,cc},d+1});
            }
            
            if(cr<n-1 && cc>0 && grid[cr+1][cc-1]!=1)
            {
                grid[cr+1][cc-1]=1;
                q.push({{cr+1,cc-1},d+1});
            }
            
            if(cc>0 && grid[cr][cc-1]!=1)
            {
                grid[cr][cc-1]=1;
                q.push({{cr,cc-1},d+1});
            }
            
            if(cr>0 && cc>0 && grid[cr-1][cc-1]!=1)
            {
                grid[cr-1][cc-1]=1;
                q.push({{cr-1,cc-1},d+1});
            }  
        }
        return -1;
    }
};
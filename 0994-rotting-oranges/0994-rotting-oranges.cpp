class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int mins=0;
        queue<pair<int,int>>q;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2)
                  q.push({i,j});
            }
        }
        
        while(!q.empty())
        {
            int n=q.size();
            bool flag=false;
            for(int i=0;i<n;i++)
            {
                int cr=q.front().first;
                int cc=q.front().second;
                q.pop();
                
                if(cr>0 && grid[cr-1][cc]==1)
              {
                flag=true;
                grid[cr-1][cc]=2;
                q.push({cr-1,cc});
              }
            
              if(cc<c-1 && grid[cr][cc+1]==1)
              {
                flag=true;
                grid[cr][cc+1]=2;
                q.push({cr,cc+1});
              }
            
              if(cr<r-1 && grid[cr+1][cc]==1)
              {
                flag=true;
                grid[cr+1][cc]=2;
                q.push({cr+1,cc});
              }
            
              if(cc>0 && grid[cr][cc-1]==1)
              {
                flag=true;
                grid[cr][cc-1]=2;
                q.push({cr,cc-1});
              }
                
            }
            
            if(flag)
                mins++;
        }
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return mins;
    }
};
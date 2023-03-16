class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        int t=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            bool flag=false;
            int s=q.size();
            
            for(int i=0;i<s;i++)
            {
                int cr=q.front().first;
                int cc=q.front().second;
                q.pop();
                
                vector<int>row{-1,0,1,0},col{0,-1,0,1};
                
                for(int i=0;i<4;i++)
                {
                    int nr=cr+row[i];
                    int nc=cc+col[i];
                    
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1)
                    {
                        q.push({nr,nc});
                        grid[nr][nc]=2;
                        flag=true;
                    }
                }
            }
            if(flag)
               t++;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                    return -1;
            }
        }

        return t;
    }
    
};
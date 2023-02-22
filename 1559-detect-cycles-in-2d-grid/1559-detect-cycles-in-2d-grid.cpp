class Solution {
public:
    
    bool helper(int cr,int cc,vector<vector<char>>&grid,int pr,int pc,vector<vector<int>>&vis)
    {  
        if(vis[cr][cc]==1)
            return true;
        
        int n=grid.size(),m=grid[0].size();
        vis[cr][cc]=1;
        
        //UP
        if(cr>0 && (cr-1!=pr || cc!=pc) && grid[cr-1][cc]==grid[cr][cc])
        {
            if(helper(cr-1,cc,grid,cr,cc,vis))
                  return true;
        }
        
        //RIGHT
        if(cc<m-1 && (cr!=pr || cc+1!=pc) && grid[cr][cc+1]==grid[cr][cc])
        {
            if(helper(cr,cc+1,grid,cr,cc,vis))
                  return true;
        }
        
        //DOWN
        if(cr<n-1 && (cr+1!=pr || cc!=pc) && grid[cr+1][cc]==grid[cr][cc])
        {
            if(helper(cr+1,cc,grid,cr,cc,vis))
                  return true;
        }
        
        //LEFT
        if(cc>0 && (cr!=pr || cc-1!=pc) && grid[cr][cc-1]==grid[cr][cc])
        {
            if(helper(cr,cc-1,grid,cr,cc,vis))
                  return true;
        }
       
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0)
                {
                    if(helper(i,j,grid,-1,-1,vis))
                      return true;
                }
            }
        }
        return false;
    }
};
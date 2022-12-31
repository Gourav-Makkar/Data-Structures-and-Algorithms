class Solution {
public:
    
    int helper(vector<vector<int>>&grid,int cr,int cc,int r,int c,vector<vector<int>>&vis,int ct)
    {
        if(cr<0 || cr==r || cc<0 || cc==c || grid[cr][cc]==-1 || vis[cr][cc]==1)
            return 0;
        
        if(grid[cr][cc]==2 && ct==0)
            return 1;
        
        vis[cr][cc]=1;
        
        int up=helper(grid,cr-1,cc,r,c,vis,ct-1);
        int right=helper(grid,cr,cc+1,r,c,vis,ct-1);
        int down=helper(grid,cr+1,cc,r,c,vis,ct-1);
        int left=helper(grid,cr,cc-1,r,c,vis,ct-1);
        
        vis[cr][cc]=0;
        
        return up+right+down+left;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        
        int cr,cc,ct=0;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==0)
                    ct++;
                if(grid[i][j]==1)
                {
                    cr=i;
                    cc=j;
                }
            }
        }
        
        ct++;
        return helper(grid,cr,cc,r,c,vis,ct);
    }
};
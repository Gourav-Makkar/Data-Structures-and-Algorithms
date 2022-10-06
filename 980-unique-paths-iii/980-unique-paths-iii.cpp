class Solution {
public:
    int ans=0;
    
    void helper(vector<vector<int>>grid,int cr,int cc,vector<vector<int>>&visited,int ct)
    {
        if(cr<0 || cr>=grid.size() || cc>=grid[0].size() || cc<0)
            return;
        if(visited[cr][cc]==1 || grid[cr][cc]==-1)
            return;
        if(grid[cr][cc]==2 && ct==1)
        {
            ans++;
            return;
        }
        visited[cr][cc]=1;
        
        helper(grid,cr,cc+1,visited,ct-1);
        helper(grid,cr+1,cc,visited,ct-1);
        helper(grid,cr,cc-1,visited,ct-1);
        helper(grid,cr-1,cc,visited,ct-1);
        
        visited[cr][cc]=0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int> (m,0));
        
        int ct=0,stRow,stCol;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                    ct++;
                if(grid[i][j]==1)
                {
                    stRow=i;
                    stCol=j;
                }
            }
        }
        ct=ct+2;
        
        helper(grid,stRow,stCol,visited,ct);
        
        return ans;
    }
};
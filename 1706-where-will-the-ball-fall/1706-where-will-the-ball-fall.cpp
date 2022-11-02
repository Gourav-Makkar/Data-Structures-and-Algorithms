class Solution {
public:
    
void helper(vector<vector<int>>&grid,int cr,int cc,int r,int c,vector<int>&ans)
{
    if(cc<0 || cc>=c)
    {
        ans.push_back(-1);
        return;
    }
    if(cr==r)
    {
        ans.push_back(cc);
        return;
    }
    if(grid[cr][cc]==1)
    {
        if(cc!=c-1 && grid[cr][cc+1]==-1)
        {
            ans.push_back(-1);
            return;
        }
        helper(grid,cr+1,cc+1,r,c,ans);
    }
    if(grid[cr][cc]==-1)
    {
        if(cc!=0 && grid[cr][cc-1]==1)
        {
            ans.push_back(-1);
            return;
        }
        helper(grid,cr+1,cc-1,r,c,ans);
    }
}
    
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans;
        int r=grid.size();
        int c=grid[0].size();
        
        for(int i=0;i<c;i++)
        {
            helper(grid,0,i,r,c,ans);
        }
        return ans;
    }
};
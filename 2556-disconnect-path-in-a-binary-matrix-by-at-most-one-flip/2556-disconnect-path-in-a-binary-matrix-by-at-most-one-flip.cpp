class Solution {
public:
       
    bool helper(int cr,int cc,vector<vector<int>>&grid,int r,int c)
    {
        if(cr==r-1 && cc==c-1)
            return true;
        
        if(cr<0 || cr==r || cc<0 || cc==c || grid[cr][cc]==0)
            return false;
        
        if(!(cr==0 && cc==0)) grid[cr][cc] = 0;
        
        bool down=helper(cr+1,cc,grid,r,c);
        if(down)
            return true;
        
        bool right=helper(cr,cc+1,grid,r,c);
        if(right)
            return true;

        return false;
    }
    
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        helper(0,0,grid,r,c);
        
        if(helper(0,0,grid,r,c))
            return false;
        return true;
    }
};
class Solution {
public:
       
    bool helper(int cr,int cc,vector<vector<int>>&grid,int r,int c,vector<pair<int,int>>&path)
    {
        if(cr==r-1 && cc==c-1)
            return true;
        
        if(cr<0 || cr==r || cc<0 || cc==c || grid[cr][cc]==0)
            return false;
        
        if(!(cr==0 && cc==0)) grid[cr][cc] = 0;
        path.push_back({cr,cc});
        
        bool down=helper(cr+1,cc,grid,r,c,path);
        if(down)
            return true;
        
        bool right=helper(cr,cc+1,grid,r,c,path);
        if(right)
            return true;
        
        path.pop_back();
        return false;
    }
    
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        
        vector<pair<int,int>>path;
        helper(0,0,grid,r,c,path);
        
        if(helper(0,0,grid,r,c,path))
            return false;
        return true;
    }
};
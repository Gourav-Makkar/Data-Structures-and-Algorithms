class Solution {
public:
       
     bool path(vector<vector<int>>& grid, int i, int j, vector<pair<int, int>> &v) {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return false;
        if(grid[i][j] == 0) return false;
        if(i == grid.size()-1 && j == grid[0].size()-1) {
            return true;
        }
        if(!(i==0 && j==0)) grid[i][j] = 0;
        v.push_back({i, j});
        if(path(grid, i, j+1, v)) {
            return true;
        }
        if(path(grid, i+1, j, v)) {
            return true;
        }
        v.pop_back();
        return false;
    }
    
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int c1 = 0;
        int c2 = 0;
        if(grid.size() <= 1 && grid[0].size() <=2) return false;
        vector<pair<int, int>> v;
        if(path(grid, 0, 0, v)) {
            for(auto [x, y]: v) {
                if(x==0 && y == 0) continue;
                grid[x][y] = 0;
            }
        }
        v.clear();
        return path(grid, 0, 0, v) == false;
    }
};
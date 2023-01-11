class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(),c=matrix[0].size();
        
        int st=0,en=c-1;
        
        while(st<r && en>=0)
        {
            if(matrix[st][en]==target)
                return true;
            else if(matrix[st][en]<target)
               st++;
            else
              en--;  
        }
        return false;
    }
};
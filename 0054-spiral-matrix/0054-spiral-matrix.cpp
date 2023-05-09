class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int startRow=0,endRow=n-1,startCol=0,endCol=m-1;
        int size=n*m;
        int ct=0;
        while(ct<size)
    {
        for(int i=startCol;i<=endCol;i++)
        {
            ans.push_back(matrix[startRow][i]);
            ct++;
        }
        startRow++;
        for(int i=startRow;i<=endRow && ct<size;i++)
        {
            ans.push_back(matrix[i][endCol]);
            ct++;
        }
        endCol--;
        for(int i=endCol;i>=startCol && ct<size;i--)
        {
            ans.push_back(matrix[endRow][i]);
            ct++;
        }
        endRow--;
        for(int i=endRow;i>=startRow && ct<size;i--)
        {
            ans.push_back(matrix[i][startCol]);
            ct++;
        }
        startCol++;
    }
        
       return ans; 
        
    }
};
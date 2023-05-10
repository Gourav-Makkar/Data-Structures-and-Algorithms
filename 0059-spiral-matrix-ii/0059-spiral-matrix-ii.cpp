class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int s=n*n;
        vector<vector<int>> ans( n , vector<int> (n)); 
        int val=1;
        int startRow=0,endRow=n-1,startCol=0,endCol=n-1;
        int ct=0;
        while(ct<s)
        {
        for(int i=startCol;i<=endCol && ct<s;i++)
        {
            ans[startRow][i]=val++;
            ct++;
        }
        startRow++;
        for(int i=startRow;i<=endRow && ct<s;i++)
        {
            ans[i][endCol]=val++;
            ct++;
        }
        endCol--;
        for(int i=endCol;i>=startCol && ct<s;i--)
        {
            ans[endRow][i]=val++;
            ct++;
        }
        endRow--;
        for(int i=endRow;i>=startRow && ct<s;i--)
        {
            ans[i][startCol]=val++;
            ct++;
        }
        startCol++;
        }
        return ans;
    }
};
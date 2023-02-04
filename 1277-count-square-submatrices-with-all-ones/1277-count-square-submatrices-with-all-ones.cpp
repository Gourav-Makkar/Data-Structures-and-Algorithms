class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                int mn=min(matrix[i-1][j],min(matrix[i-1][j-1],matrix[i][j-1]));
                if(matrix[i][j]==1)
                    matrix[i][j]+=mn;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                ans+=matrix[i][j];
        }
        return ans;
    }
};
class Solution {
public:
    
    int helper(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&dp)
    {
        if(j<0 || j>=matrix[0].size())
            return 1e9;
        if(i==matrix.size()-1)
            return matrix[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down=matrix[i][j]+helper(matrix,i+1,j,dp);
        int diagLeft=matrix[i][j]+helper(matrix,i+1,j-1,dp);
        int diagRight=matrix[i][j]+helper(matrix,i+1,j+1,dp);
        
        return dp[i][j]=min(down,min(diagLeft,diagRight));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        int ans=INT_MAX;
        
        vector<vector<int>>dp(r,vector<int>(c,-1));
        for(int i=0;i<c;i++)
        {
            ans=min(ans,helper(matrix,0,i,dp));
        }
        return ans;
    }
};
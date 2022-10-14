class Solution {
public:
    
    int helper(vector<vector<int>>&triangle,int i,int j,int n,vector<vector<int>>&dp)
    {
        if(i==n-1)
        {
            return triangle[i][j];
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down=triangle[i][j]+helper(triangle,i+1,j,n,dp);
        
        int diag=triangle[i][j]+helper(triangle,i+1,j+1,n,dp);
        
        return dp[i][j]=min(down,diag);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
       int n=triangle.size();
       vector<vector<int>>dp(n,vector<int>(n,-1));
       return helper(triangle,0,0,n,dp);
    }
};
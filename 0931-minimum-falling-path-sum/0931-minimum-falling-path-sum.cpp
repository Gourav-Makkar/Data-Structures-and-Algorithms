class Solution {
public:
    
    int helper(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&dp)
    {
        if(j<0 || j>=matrix.size())
            return 1e9;
        if(i==matrix.size()-1)
            return matrix[i][j]; 
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        int down=matrix[i][j]+helper(matrix,i+1,j,dp);
        int leftDiag=matrix[i][j]+helper(matrix,i+1,j-1,dp);
        int rightDiag=matrix[i][j]+helper(matrix,i+1,j+1,dp);
        
        return dp[i][j]=min(down,min(leftDiag,rightDiag));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
         
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,helper(matrix,0,i,dp));
        }
        return ans;
    }
};
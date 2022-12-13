class Solution {
public:
    
    int helper(vector<vector<int>>&matrix,int cr,int cc,int r,int c,vector<vector<int>>&dp)
    {
        if(cc<0 || cc>=c)
            return 1e9;
        if(cr==r-1)
            return matrix[cr][cc];
        
        if(dp[cr][cc]!=-1)
            return dp[cr][cc];
        
        int down=matrix[cr][cc]+helper(matrix,cr+1,cc,r,c,dp);
        int ldiag=matrix[cr][cc]+helper(matrix,cr+1,cc-1,r,c,dp);
        int rdiag=matrix[cr][cc]+helper(matrix,cr+1,cc+1,r,c,dp);
        
        return dp[cr][cc]=min(down,min(ldiag,rdiag));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        
        int ans=INT_MAX;
        vector<vector<int>>dp(r,vector<int>(c,-1));
        for(int i=0;i<c;i++)
        {
            ans=min(ans,helper(matrix,0,i,r,c,dp));
        }
        return ans;
    }
};
class Solution {
public:
    
    int helper(int dr,int dc,vector<vector<int>>&dp)
    {
        if(dr==0 && dc==0)
            return 1;
        if(dr<0 || dc<0)
            return 0;
        
        if(dp[dr][dc]!=-1)
            return dp[dr][dc];
        int up=helper(dr-1,dc,dp);
        int left=helper(dr,dc-1,dp);
        
        return dp[dr][dc]=up+left;   
        
    }
   
    int uniquePaths(int m, int n) {
        
        int dr=m-1,dc=n-1;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans=0;
        ans+=helper(dr,dc,dp);
        
        return ans;
    }
};
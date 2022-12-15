class Solution {
public:
    
    int helper(vector<char>&vow,int idx,int n,vector<vector<int>>&dp)
    {
        if(n==0)
            return 1;
        if(idx==5)
            return 0;
        
        if(dp[idx][n]!=-1)
            return dp[idx][n];
        
        int ans=0;
        
        ans+=helper(vow,idx+1,n,dp);
        ans+=helper(vow,idx,n-1,dp);
        
        return dp[idx][n]=ans;
    }
    
    int countVowelStrings(int n) {
        vector<char>vow={'a','e','i','o','u'};
        
        vector<vector<int>>dp(5,vector<int>(n+1,-1));
        
        return helper(vow,0,n,dp);
    }
};
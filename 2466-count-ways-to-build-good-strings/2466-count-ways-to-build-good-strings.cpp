class Solution {
public:
    int mod=1e9+7;
    int helper(int low,int high,int z,int o,int curr,vector<int>&dp)
    {
        if(curr>high)
            return 0;
        int ans=0;
        
        if(dp[curr]!=-1)
            return dp[curr];
        if(curr>=low && curr<=high)
        {
            ans=(1 + helper(low,high,z,o,curr+z,dp) + helper(low,high,z,o,curr+o,dp))%mod;
        }
        else
            ans=(0+helper(low,high,z,o,curr+z,dp) + helper(low,high,z,o,curr+o,dp))%mod;
        
        return dp[curr]=ans;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
    
        vector<int>dp(high+1,-1);
        return helper(low,high,zero,one,0,dp);
    }
};
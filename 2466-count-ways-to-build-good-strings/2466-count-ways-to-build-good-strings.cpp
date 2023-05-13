class Solution {
public:
    int mod=1000000007;
    
    int helper(int len,int &low,int &high,int &zero,int &one,vector<int>&dp)
    {
        if(len>high)
            return 0;
        
        if(dp[len]!=-1)
            return dp[len];
        
        if(len>=low && len<=high)
            return dp[len]=(1+helper(len+zero,low,high,zero,one,dp)+helper(len+one,low,high,zero,one,dp))%mod;
        
        return dp[len]=(helper(len+zero,low,high,zero,one,dp)+helper(len+one,low,high,zero,one,dp))%mod;
    }
    
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        return helper(0,low,high,zero,one,dp);
    }
};
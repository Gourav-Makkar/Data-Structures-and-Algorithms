class Solution {
public:
    
    int helper(vector<int>&nums,int idx,vector<int>&dp)
    {
        if(idx<0)
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int take=nums[idx]+helper(nums,idx-2,dp);
        int notTake=0+helper(nums,idx-1,dp);
        
        return dp[idx]=max(take,notTake);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return helper(nums,n-1,dp);
    }
};
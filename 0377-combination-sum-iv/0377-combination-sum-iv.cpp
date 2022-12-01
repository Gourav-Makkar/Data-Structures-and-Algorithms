class Solution {
public:
    
    int helper(vector<int>&nums,int target,int n,vector<int>&dp)
    {
        if(target==0)
            return 1;
       
        if(dp[target]!=-1)
            return dp[target];
        int ct=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=target)
                ct+=helper(nums,target-nums[i],n,dp);
        }
        
        return dp[target]=ct;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>dp(target+1,-1);
        return helper(nums,target,n,dp);
        
        
    }
};
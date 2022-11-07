class Solution {
public:
     int helper(vector<int>&nums,int idx,int cs,int target,vector<vector<int>>&dp)
    {
        if(idx==nums.size())
        {
            if(cs==target)
                return 1;
            return 0;
        }
         if(cs>=0 && dp[idx][cs+1000]!=-1)
             return dp[idx][cs+1000];
        int pos=helper(nums,idx+1,cs+nums[idx],target,dp);
        int neg=helper(nums,idx+1,cs-nums[idx],target,dp);
        
        return dp[idx][cs+1000]=(pos+neg);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(20,vector<int>(2000+1,-1));
        return helper(nums,0,0,target,dp);
    }
};
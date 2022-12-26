class Solution {
public:
    
    bool helper(vector<int>&nums,int idx,vector<int>&dp)
    {
        if(idx==nums.size()-1)
            return true;
        
        if(idx==nums.size())
            return false;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        for(int i=1;i<=nums[idx];i++)
        {
            if(helper(nums,idx+i,dp))
                return dp[idx]=true;
        }
        return dp[idx]=false;
    }
    
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>dp(n,-1);
        return helper(nums,0,dp);
    }
};
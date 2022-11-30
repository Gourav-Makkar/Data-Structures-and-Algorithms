class Solution {
public:
    
    int helper(vector<int>&nums,int idx,int des,vector<int>&dp)
    {
        if(idx==des)
            return 0;
        if(idx>des)
            return 1e9;
        if(dp[idx]!=-1)
            return dp[idx];
        int ans=1e9;
        for(int i=1;i<=nums[idx];i++)
        {
            int curr=1 + helper(nums,idx+i,des,dp);
            ans=min(ans,curr);
        }
        return dp[idx]=ans;
    }
    
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return helper(nums,0,n-1,dp);
    }
};
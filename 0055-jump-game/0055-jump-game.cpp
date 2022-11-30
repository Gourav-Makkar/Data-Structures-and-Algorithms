class Solution {
public:
    
    bool helper(vector<int>&nums,int idx,int des,vector<int>&dp)
    {
        if(idx==des)
            return true;
        if(idx>des)
            return false;
        
        if(dp[idx]!=-1)
            return dp[idx];
        for(int i=1;i<=nums[idx];i++)
        {
            if(helper(nums,idx+i,des,dp)==true)
                return dp[idx]=true;
        }
        return dp[idx]=false;
    }
    
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool>dp(n,false);
        // return helper(nums,0,n-1,dp);
        dp[n-1]=true;
        for(int idx=n-2;idx>=0;idx--)
        {
            for(int i=1;i<=nums[idx];i++)
            {
                if(idx+i>=n)
                    break;
                if(dp[idx+i])
                {
                    dp[idx]=true;
                    break;
                }
            }
        }
       return dp[0];
    }
};
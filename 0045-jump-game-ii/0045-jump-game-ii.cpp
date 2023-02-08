class Solution {
public:
    
    long long helper(int idx,vector<int>&nums)
    {
        int n=nums.size();
        if(idx==n-1)
            return 0;
        
        long long ans=INT_MAX;
        for(int i=1;i<=nums[idx];i++)
        {
            if(idx+i<=n-1)
            {
                long long ct=1+helper(idx+i,nums);
                ans=min(ans,ct);
            }
        }
        return ans;
    }
    
    int jump(vector<int>& nums) {
        int n=nums.size();
        
        // return helper(0,nums);
        
        vector<long long>dp(n,INT_MAX);
        dp[n-1]=0;
        
        for(int idx=n-2;idx>=0;idx--)
        {
            for(int i=1;i<=nums[idx];i++)
            {
                if(idx+i<=n-1)
                {
                    long long ct=1+dp[idx+i];
                    dp[idx]=min(dp[idx],ct);
                }
            }
        }
        return dp[0];
    }
};
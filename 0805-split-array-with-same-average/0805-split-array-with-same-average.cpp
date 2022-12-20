#define ll long long
class Solution {
public:
    
    bool helper(vector<int>&nums,int target,int idx,int len,vector<vector<vector<bool>>>&dp)
    {
       if(len==0)
            return target==0;
        
       if(idx<0)
           return false;
        
       if(target<0)
           return false;

        if(dp[idx][len][target]==false)
            return false;
        
        bool take=helper(nums,target-nums[idx],idx-1,len-1,dp);
        bool notTake=helper(nums,target,idx-1,len,dp);
        
        return dp[idx][len][target] = take||notTake;
    }
    
    bool splitArraySameAverage(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        
        for(int i=0;i<n;i++)
            sum+=nums[i];
        
        vector<vector<vector<bool>>>dp(n,vector<vector<bool>>(n,vector<bool>(sum+1,true)));
        
        for(int i=1;i<=n/2;i++)
        {
            if((sum*i)%n==0)
            {
                if(helper(nums,(sum*i)/n,n-1,i,dp))
                    return true;
            }
        }
        return false;
    }
};
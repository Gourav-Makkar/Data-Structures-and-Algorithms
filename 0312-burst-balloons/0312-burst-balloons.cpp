class Solution {
public:
    
    int helper(int i,int j,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int coins=INT_MIN;

        for(int k=i;k<=j;k++)
        {
            coins=max(coins,helper(i,k-1,nums,dp) + nums[i-1]*nums[k]*nums[j+1] + helper(k+1,j,nums,dp));
        }
        
        return dp[i][j]=coins;
    }
    
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(1,n-2,nums,dp);
    }
};
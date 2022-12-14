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
        if(nums.size()==1)
            return nums[0];
        
        vector<int>temp1,temp2;
        
        for(int i=0;i<n;i++)
        {
            if(i!=0)
                temp1.push_back(nums[i]);
            if(i!=n-1)
                temp2.push_back(nums[i]);
        }
        
        vector<int>dp1(n-1,-1);
        int ans1=helper(temp1,temp1.size()-1,dp1);
        
        vector<int>dp2(n-1,-1);
        
        int ans2=helper(temp2,temp2.size()-1,dp2);
        
        return max(ans1,ans2);
    }
};
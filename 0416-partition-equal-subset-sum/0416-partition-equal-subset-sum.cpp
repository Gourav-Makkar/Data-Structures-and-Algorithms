class Solution {
public:
    
//     bool helper(vector<int>nums,int idx,int target,vector<vector<int>>&dp)
//     {
//         if(target==0)
//             return true;
//         if(idx==0)
//         {
//             return (nums[idx]==target);
//         }
//         if(dp[idx][target]!=-1)
//             return dp[idx][target];
//         bool nt=helper(nums,idx-1,target,dp);
//         bool t=false;
//         if(nums[idx]<=target)
//             t=helper(nums,idx-1,target-nums[idx],dp);
        
//         return dp[idx][target]=(t || nt);
        
//     }
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0 || n==1)
            return false;
       vector<vector<bool>>dp(n,vector<bool>(sum/2 + 1,false));
        // return helper(nums,n-1,sum/2,dp);th
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        if(nums[0]<=sum/2)
            dp[0][nums[0]]=true;
        for(int i=1;i<n;i++)
        {
            for(int target=1;target<=sum/2;target++)
            {
                bool nt=dp[i-1][target];
                bool t=false;
                if(nums[i]<=target)
                    t=dp[i-1][target-nums[i]];
                
                dp[i][target]=(t || nt);
            }
        }
        return dp[n-1][sum/2];
    }
};
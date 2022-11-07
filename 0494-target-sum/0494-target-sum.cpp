class Solution {
public:
    
    int helper(vector<int>&nums,int target,int idx)
    {
        if(idx==0)
        {
            if(target==0 && nums[0]==0)
                return 2;
            if(target==0 || nums[0]==target)
                return 1;
            return 0;
        }
        int nt=helper(nums,target,idx-1);
        int t=0;
        if(nums[idx]<=target)
            t=helper(nums,target-nums[idx],idx-1);
        return t+nt;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        if(sum<target || (sum-target)%2!=0)
            return 0;
        int tar=(sum-target)/2;
        
        return helper(nums,tar,n-1);
    }
};
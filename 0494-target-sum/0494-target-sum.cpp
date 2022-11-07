class Solution {
public:
    
    int helper(vector<int>&nums,int target,int idx,int cs)
    {
        if(idx==nums.size())
        {
            if(cs==target)
                return 1;
            return 0;
        }
        
        int p=helper(nums,target,idx+1,cs+nums[idx]);
        int m=helper(nums,target,idx+1,cs-nums[idx]);
        
        return (p+m);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        
        return helper(nums,target,0,0);
    }
};
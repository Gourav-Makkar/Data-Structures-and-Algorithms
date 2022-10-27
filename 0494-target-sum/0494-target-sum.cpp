class Solution {
public:
    
    int helper(vector<int>&nums,int idx,int cs,int target)
    {
        if(idx==nums.size())
        {
            if(cs==target)
                return 1;
            return 0;
        }
        int pos=helper(nums,idx+1,cs+nums[idx],target);
        int neg=helper(nums,idx+1,cs-nums[idx],target);
        
        return (pos+neg);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return helper(nums,0,0,target);
    }
};
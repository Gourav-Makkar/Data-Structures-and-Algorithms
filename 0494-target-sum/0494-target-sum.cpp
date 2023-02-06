class Solution {
public:
    
    int helper(int idx,int cs,vector<int>&nums,int target)
    {
        if(idx==nums.size())
        {
            if(cs==target)
                return 1;
            return 0;
        }
        int pos=helper(idx+1,cs+nums[idx],nums,target);
        int neg=helper(idx+1,cs-nums[idx],nums,target);
        
        return pos+neg;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        
        return helper(0,0,nums,target);
    }
};
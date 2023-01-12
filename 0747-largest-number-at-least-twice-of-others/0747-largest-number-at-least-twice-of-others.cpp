class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx=INT_MIN;
        int idx=-1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>mx)
            {
                mx=nums[i];
                idx=i;
            }
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(i!=idx)
            {
                if(2*nums[i]>mx)
                    return -1;
            }
        }
        return idx;
    }
};
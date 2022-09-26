class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int cs=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(cs+nums[i]>nums[i])
            {
                cs+=nums[i];
            }
            else
                cs=nums[i];
            ans=max(ans,cs);
        }
        return ans;
    }
};
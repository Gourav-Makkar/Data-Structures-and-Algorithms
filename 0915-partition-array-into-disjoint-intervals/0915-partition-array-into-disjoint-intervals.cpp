class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        int till_mx=nums[0],overall_mx=nums[0],ans=0;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]<till_mx)
            {
                ans=i;
                till_mx=overall_mx;
            }
           overall_mx=max(overall_mx,nums[i]);
        }
        return ans+1;
    }
};
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        int mn=nums[0],mx=nums[0],ans=0;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]<mn)
            {
                ans=i;
                mn=mx;
            }
            mx=max(mx,nums[i]);
        }
        return ans+1;
    }
};
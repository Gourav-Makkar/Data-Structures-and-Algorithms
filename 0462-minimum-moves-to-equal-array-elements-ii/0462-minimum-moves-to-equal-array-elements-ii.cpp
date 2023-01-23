class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        if(n%2==0)
        {
            int f=n/2;
            int s=(n-1)/2;
            
            int ans1=0,ans2=0;
            for(auto it:nums)
            {
                ans1+=abs(it-nums[f]);
                ans2+=abs(it-nums[s]);
            }
            return min(ans1,ans2);
        }
        else
        {
            int idx=n/2,ans=0;
            for(auto it:nums)
                ans+=abs(nums[idx]-it);
            return ans;
        }
    }
};
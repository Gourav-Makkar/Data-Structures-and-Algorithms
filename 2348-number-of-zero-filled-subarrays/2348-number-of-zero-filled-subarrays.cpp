class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n=nums.size();
        
        long long ans=0,ct=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                ct++;
            else
            {
                ans+=(ct)*(ct+1)/2;
                ct=0;
            }
        }
        if(ct!=0)
            ans+=(ct)*(ct+1)/2;
        
        return ans;
    }
};
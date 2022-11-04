class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0,i=0;
        int ans=0;
        
        long long p=1;
        
        while(j<n)
        {
            p=p*nums[j];
            while(p>=k && i<=j)
            {
                p=p/nums[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        
        while(i<j)
        {
            ans=max(ans,nums[i]+nums[j]);
            i++;
            j--;
        }
        return ans;
    }
};